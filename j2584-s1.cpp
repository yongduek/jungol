/***
http://blog.daum.net/_blog/BlogTypeView.do?blogid=0cH2t&articleno=7&_bloghome_menu=recenttext

일단 D[i]를 1 ~ i까지의 최대라고 정의하자
그러면 D[i]를 i~1까지 높이차가 S이상 인 max(D[j]+C[i],D[i-1])이라고 할 수 있다. (C[i]는 가격)
높이차가 S이상인 것이 없으면 그냥 max(C[i],D[i-1])이라고 할 수 있다.
i~1까지 그냥 찾으면 O(n*n)으로 60%만 점수를 얻을 수 있다.
조금 더 생각해 보면 D[k-1]<=D[k]<=D[k+1]가 성립하기 때문에 이분탐색으로 찾을 수 있다.
이분탐색으로 높이차가 S이상 인 것을 찾게되면 100점을 맞을 수 있다. 시간복잡도는 O(n log n)
***/

#include<stdio.h>
#include<algorithm>
using namespace std;
struct pp{
    int h;
    int c;
}ar[300001];
bool cmp(const struct pp &a,const struct pp &b)
{
    return a.h<b.h;
}
int ans[300001];
int main()
{
    struct pp a;
    int n,s,i,j;
 
    scanf("%d %d",&n,&s);
 
    for(i=1;i<=n;i++)
        scanf("%d %d",&ar[i].h,&ar[i].c);
 
    sort(ar+1,ar+n+1,cmp);
 
    ans[1]=ar[1].c;
    for(i=2;i<=n;i++){
        a.c=1001;
        a.h=ar[i].h-s;
        j=upper_bound(ar+1,ar+1+n,a,cmp)-ar-1;
        if(ar[j].h>ar[i].h-s) ans[i]=ans[i-1];
        else{
            ans[i]=ans[j]+ar[i].c;
            if(ans[i]<ans[i-1]) ans[i]=ans[i-1];
        }
    }
 
    printf("%d",ans[n]);
}

