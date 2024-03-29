https://codeforces.com/blog/entry/7383


S = the max integer number which is less than sqrt(N);
/* or B*B >= N where N=no of elements in our array */
bool cmp(Query A, Query B)
{
  if (A.l / S != B.l / S) return A.l / S < B.l / S;
  return A.r > B.r;
}

Above can give RE use it : by Arpa          https://codeforces.com/blog/entry/7383
bool cmp(Query A, Query B){
  if (A.l / S ！= B.l / S) return A.l < B.l;
  return A.l / S % 2 ? A.r > B.r : A.r < B.r;
}


/* Dquery SPOJ */
/* Given a sequence of n numbers a 1 , a 2 , ..., a n and a number of d-queries. A d-query is a pair (i, j) (1 ≤ i ≤ j ≤ n). For each query-d (i, j), you need to return the number of distinct elements in the sub sequence a i , a i + 1 , ..., a j.*/
int answer;
struct query
{
    int l,r,ind;
}Q[M];
int ans[M];
int a[N];
int cnt[A];
 
void add(int index)
{
    cnt[a[index]]++;
    if(cnt[a[index]]==1) answer++;
}
 
void remove(int index)
{
    cnt[a[index]]--;
    if(cnt[a[index]]==0) answer--;
}
 
bool cmp(query f,query s)
{
    if((f.l/BLOCK)!=(s.l/BLOCK))
        return (f.l/BLOCK)<(s.l/BLOCK);
    else
        return f.r<s.r;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    int n,q;
    scanf("%d",&n);
    REP(i,0,n)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&q);
    REP(i,0,q)
    {
        scanf("%d%d",&Q[i].l,&Q[i].r);
        Q[i].ind=i;
        Q[i].l--;
        Q[i].r--;
    }
    sort(Q,Q+q,cmp);
    int cl=0,cr=0;
		// Element considered from [cl,cr-1]
    REP(i,0,q)
    {
        int left=Q[i].l,right=Q[i].r;
        while(cl<left)
            remove(cl),cl++;
        while(cl>left)
            add(cl-1),cl--;
        while(cr<=right)
            add(cr),cr++;
        while(cr>(right+1))
            remove(cr-1),cr--;
        ans[Q[i].ind]=answer;
    }
    REP(i,0,q)
        printf("%d\n",ans[i]);
    return 0;
}
