#include <cstdio>
class Queue
{
	int *arr, max_size, cur_size;
public:
	Queue(int n): max_size(n), cur_size(0)
	{
		arr=new int[max_size+1];
	}

	~Queue()
	{
		delete arr;
	}

	void push(int num)
	{
		if(cur_size==max_size)
		{
			error(1);
			return;
		}

		arr[++cur_size]=num;
		int pos=cur_size, temp;
		while(pos!=1)
		{
			if(arr[pos/2]>=arr[pos])
				break;

			temp=arr[pos], arr[pos]=arr[pos/2], arr[pos/2]=temp;
			pos/=2;
		}
	}

	int pop()
	{
		if(cur_size==0)
		{
			error(2);
			return 0;
		}

		int val=arr[1], pos=1, temp;
		arr[1]=arr[cur_size--];
		while(pos*2<=cur_size)
		{
			if(arr[pos]>=arr[pos*2])
				break;

				temp=arr[pos], arr[pos]=arr[pos*2], arr[pos*2]=temp;
				pos*=2;
		}

		return val;
	}

	void clear()
	{
		cur_size=0;
	}

private:void error(int error_type)
	{
		switch(error_type)
		{
		case 1:
			printf("OVER_SIZE"); break;

		case 2:
			printf("IS EMPTY"); break;
		}
	}
};
// int main()
// {
// 	Queue Q(1000);
// 	Q.push(2);
// 	printf("%d", Q.pop());
// }
