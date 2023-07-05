#include<iostream>

using namespace std;


const int QUEUE_SIZE{ 10 };

enum Command
{
	// 큐에 집어 넣기라는 뜻
	ENQUEUE = 1,
	// 큐에서 뺀다는 뜻
	DEQUEUE = 2,
	QUIT = 3
};

struct Queue
{
	int cotainer[QUEUE_SIZE]{};
	int head{};
	int tail{};
};

void PrintInfo()
{
	cout << "<QUEU>" << endl;
	cout << "1. ENQUEUE" << endl << "2. DEQUEUE" << endl << "3. QUIT" << endl;
	cout << "--------------" << endl;
}

void PrintQueue(Queue& queue)
{
	int i = queue.head;

	if (queue.head == queue.tail)
	{
		cout << "Empty" << endl;
		return;
	}
	while (i != queue.tail)
	{
		// haed 다음 부터 출력
		i = (i + 1) % QUEUE_SIZE;
		cout << queue.cotainer[i] << endl;
	}

	cout << "---------" << endl;
}

void EnQueue(Queue& queue, int value)
{
	// 안전 장치
	// 큐가 가득 찼다면
	if ( (queue.tail + 1) % QUEUE_SIZE == queue.head)
	{
		cout << "QUEUE is FULL!" << endl;
		return;
	}
	
	queue.tail = (queue.tail + 1) % QUEUE_SIZE;
	queue.cotainer[queue.tail] = value;
}

void DeQueue(Queue& queue)
{

	// 안전 장치
	if (queue.head == queue.tail)
	{
		cout << "QUEUE is already EMPTY" << endl;
	}

	queue.head = (queue.head + 1) % QUEUE_SIZE;
}

int main()
{
	cout << "Circlear QUEUE" << endl;

	Queue IsQueue;

	PrintInfo();

	int command{};

	while (true)
	{
		PrintQueue(IsQueue);
		cout << ">";
		cin >> command;

		switch (command)
		{
		case ENQUEUE:
		{
			int value;
			cout << "\tvalue : ";
			cin >> value;
			EnQueue(IsQueue, value);
		}
		break;
		case DEQUEUE:
		{
			DeQueue(IsQueue);
		}
		break;
		case QUIT:
		{
			return 0;
		}
		break;

		default:
			cout << "잘못된 명령입니다." << endl;
			break;
		}
	}
}