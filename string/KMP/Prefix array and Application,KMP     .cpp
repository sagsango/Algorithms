/*

   Creating prefix array in O(n)
   This is an online algorithm
   
   You are given a string s of length n. The prefix function for this string is defined as an array π of length n, 
   where π[i] is the length of the longest proper prefix of the substring s[0…i] which is also a suffix of this substring. 
   A proper prefix of a string is a prefix that is not equal to the string itself. By definition, π[0]=0.

*/
vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
