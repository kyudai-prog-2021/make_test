#include<stdio.h>
#include<math.h>

void merge(int a[],int temp[], int left, int right){
    int mid, i, j, k;
    
    if(left < right){
        //分割
        mid = (left + right)/2.0;
        merge(a, temp,left, mid);
        merge(a, temp,mid+1, right);

        //前半の代入
        for(i = left; i <= mid; i++){
            temp[i] = a[i];
        }
        //後半の逆順代入
        for(j = mid+1; j <= right; j++){
            temp[right - (j- (mid+1))] = a[j];
        }
        
        i = left;
        j = right;
        for(k = left; k <= right; k++){
            if(temp[i] < temp[j]){
                a[k] = temp[i++];
            }
            else{
                a[k] = temp[j--];
            }
        }
    }

}

/* マージソート関数 */
void mergesort(int a[],int left,int right,int N){
    int mid, i, j, k, temp[N];
    merge(a,temp,left,right);
}

int main()
{
    int N, i;

    //要素数
    scanf("%d", &N);
    int a[N];

    //入力データを配列a[N]に格納
    for(i=0;i<N;i++){
        scanf("%d",&a[i]);
    }

    mergesort(a,0,N,N);
    //ソート結果を出力
    for(i=0;i<N;i++){
        printf("%d\n",a[i]);
    }
}