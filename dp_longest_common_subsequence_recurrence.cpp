int values(string s,string t,int ind1,int ind2){
	if(ind1<0 || ind2<0){
		return 0;
	}
	if(s[ind1]==t[ind2]){
		return 1+values(s,t,ind1-1,ind2-1);
	}
	else{
		return max(values(s,t,ind1,ind2-1),values(s,t,ind1-1,ind2));
	}
}
int lcs(string s, string t)
{
	return values(s,t,s.size()-1,t.size()-1);
}
