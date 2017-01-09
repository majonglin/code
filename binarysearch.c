#include <stdio.h>
//testcase:陣列only1,2,3..個元素
//http://program-lover.blogspot.tw/2008/08/binary-search.html
int binarysearch(int * head, int search, int n){
	/*
		case array[]={1,1,1,2,2,5,5,5}
		this method will not return first element of given value
	*/
	int low=0;
	int high=n-1;
	while(low<=high){
		//int mid = (low + high) / 2;
		int mid=low+(high-low)/2;// in case of overflow
		if(search==head[mid]) return mid;
		else if(search>head[mid])low=mid+1;
		else high=mid-1;

	}		
	return -1;

}
int binarysearch_advance(int * head, int search, int n){
	/*
		case array[]={1,1,1,2,2,5,5,5}
		this method will return first element of given value
	*/
	int low=0;
	int high=n-1;
	while(low<=high){
		//int mid = (low + high) / 2;
		int mid=low+(high-low)/2;// in case of overflow
		if(search==head[mid]){
			int i;
			for(i=mid;i-1>=0 && head[i-1]==search;i--);
			return i;
		}		
		else if(search>head[mid])low=mid+1;
		else high=mid-1;

	}		
	return -1;

}
void bubbleSort(int *head,int num){
	int i,j;	
	for(i=0;i<num;i++){
		for(j=num-1;j>i;j--){
			if(head[j]<head[j-1]){
				int tmp=head[j];
				head[j]=head[j-1];
				head[j-1]=tmp;
			}
		}
	
	}



}

int main(int argc, char* argv[]) {
	int search, ans,i;
    int data[] = {1,5,2,5,1,2,5};
	
//part 1:bubble sort
	bubbleSort(data,sizeof(data) / sizeof(int));
//part 2:binary search	

    printf("請輸入欲搜尋的資料: ");
    scanf("%d", &search);
	// 呼叫函式進行搜尋
    ans = binarysearch_advance(data, search, sizeof(data) / sizeof(int));

    if (ans < 0)
    {
        printf("找不到 %d\n", search);
    }
    else
    {
        printf("在第 %d 筆資料找到 %d\n", ans, search);
    }
	
	return 0;
}
