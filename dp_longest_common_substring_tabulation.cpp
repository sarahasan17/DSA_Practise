       for(int j=1;j<=m;j++){
           if(str1[i-1]==str2[j-1]){
               dp[i][j]=dp[i-1][j-1]+1;
               if(max<dp[i][j]){
                   max=dp[i][j];
                   row=i;
                   col=j;
               }
           }
           else{
               dp[i][j]=0;
           }
       }
   }
   string str="";
   while(dp[row][col]!=0){
       str=str+str1[row-1];
       row--;
       col--;
   }
   string pb="";
   for(int i=str.size()-1;i>=0;i--){
       pb=pb+str[i];
   }
   return max;
}
