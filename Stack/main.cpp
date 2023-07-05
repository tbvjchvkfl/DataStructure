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

	// ���Ұ� ������ ���� ���¸� �����ϱ� ���ؼ� �⺻ ���� -1�� ���
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
			cout << "�߸��� ����Դϴ�." << endl;
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

	// ���� ��ġ 
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
	// ���� ��ġ
	// ���ÿ� ���� ���� á��!!!
	// �迭�� ���Ҵ� �� 3��
	// ������ �ε��� ��ȣ�� 2�� �����ϱ�
	// ������ ���� �������� 1�� �� ���� ���ų� Ŭ ���� ����
	if (stack.topIndex >= STACK_SIZE - 1)
	{
		cout << "Stack is FULL!!" << endl;
		return;
	}

	// �迭�� �ε����� -1���� �����̴ϱ� �ε����� ���� �����ϸ鼭 ���� ������.
	stack.container[++stack.topIndex] = value;
}

void Pop(Stack& stack)
{

	// ���� ��ġ
	// �迭�� �ε��� ���� 0���� �۾����� �ȵǴϱ�
	if (stack.topIndex < 0)
	{
		cout << "Stack is empty!" << endl;
		return;
	}
	stack.topIndex--;
}
