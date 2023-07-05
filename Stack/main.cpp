#include<iostream>

using namespace std;

const int STACK_SIZE{ 10 };

enum Command
{
	PUSH = 1,
	POP = 2,
	QUIT = 3
};

struct Stack
{
	int container[STACK_SIZE]{};

	// 원소가 들어가있지 않은 상태를 구분하기 위해서 기본 값을 -1로 사용
	int topIndex{ -1 };
};


void UserInteract(Stack& stack);
void Push(Stack& stack, int value);
void Pop(Stack& stack);
void PrintStack(Stack& stack);

int main()
{
	Stack IsStack;
	
	int command{};
	UserInteract(IsStack);

	while (true)
	{
		
		PrintStack(IsStack);
		cout << ">";
		cin >> command;

		switch (command)
		{
		case PUSH:
		{
			int value{};
			cin >> value;
			Push(IsStack, value);
			
		}
		break;
		case POP:
		{
			Pop(IsStack);
		}
		break;
		case QUIT:
		{
			return 0;
		}
		break;
		default:
		{
			cout << "잘못된 명령입니다." << endl;
		}
		break;
		}
	}
	return 0;
}

void UserInteract(Stack& stack)
{
	cout << "STACK" << endl;
	cout << "---------------------" << endl;
	cout << "1. Push" << endl;
	cout << "2. POP" << endl;
	cout << "3. Quit" << endl;
}

void PrintStack(Stack& stack)
{
	cout << "--- stack ---" << endl;

	// 안전 장치 
	if (stack.topIndex < 0)
	{
		cout << "Empty" << endl;
		return;
	}
	for (int i = stack.topIndex; i >= 0; i--)
	{
		cout << stack.container[i] << endl;
	}
}

void Push(Stack& stack, int value)
{
	// 안전 장치
	// 스택에 값이 가득 찼다!!!
	// 배열의 원소는 총 3개
	// 하지만 인덱스 번호는 2번 까지니까
	// 범위는 원소 개수에서 1을 뺀 값을 같거나 클 때로 설정
	if (stack.topIndex >= STACK_SIZE - 1)
	{
		cout << "Stack is FULL!!" << endl;
		return;
	}

	// 배열의 인덱스는 -1부터 시작이니까 인덱스가 먼저 증가하면서 값이 들어가야함.
	stack.container[++stack.topIndex] = value;
}

void Pop(Stack& stack)
{

	// 안전 장치
	// 배열의 인덱스 값이 0보다 작아지면 안되니까
	if (stack.topIndex < 0)
	{
		cout << "Stack is empty!" << endl;
		return;
	}
	stack.topIndex--;
}
