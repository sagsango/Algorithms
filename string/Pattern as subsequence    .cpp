//given a text and a pattern , find no of times pattern appeared as subsequence in the text
//https://www.techiedelight.com/count-number-times-pattern-appears-given-string-subsequence/


//without memoisation
int cnt=0;
void fun(string s1,int i1,string s2,int i2)
{
	if( i1==s1.length() )
	{
		if(i2==s2.length())cnt++;
	}
	else if(s1[i1]==s2[i2])
	{
		fun(s1,i1+1,s2,i2);
		fun(s1,i1+1,s2,i2+1);
	}
	else
	{
		fun(s1,i1+1,s2,i2);
	}
}
				
int32_t main()
{
	IOS
	string s1="subsequenceefweseuwdcvdseurtgue";
	string s2="sue";
	fun(s1,0,s2,0);
	cout<<cnt<<endl;
}


//with memoisation
int cache[MAXLENGTH][MAXLENGTH];//initialised with -1
void fun(string s1,int i1,string s2,int i2)
{
	if( i1==s1.length() )
	{
		if(i2==s2.length())return cache[i1][i2]=1;
                else return  cache[i1][i2]=0;
	}
	else if( cache[i1][i2]!= -1 )return cache[i1][i2];
	else
	{
	       cache[i1][i2]=0;
	       if(s1[i1]==s2[i2])
	       {
		   cache[i1][i2]+= fun(s1,i1+1,s2,i2);
		   cache[i1][i2]+= fun(s1,i1+1,s2,i2+1);
	       }
	       else
	       {
		    cache[i1][i2]+= fun(s1,i1+1,s2,i2);
	       }
		return cache[i1][i2];
	}
}

