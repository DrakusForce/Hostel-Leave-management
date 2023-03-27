#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<complex>
#include<cstring>
#include<string>
#include<set>
#include<map>
#include<list>
#include<vector>
#include<fstream>
using namespace std;
#define int long long
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    string str;
    cin>>str;
    int n=str.size();
    int arr[27]={0};
    int b[27]={0};
    int sma=INT_MAX;
    for(int i=0;i<n;i++){
        if(str[i]>='a' && str[i]<='z') arr[str[i]-'a']++;
        else b[str[i]-'A']++;
    }

    for(int i=0;i<26;i++){
        if(arr[i]>0)sma=min(sma,arr[i]);
        if(b[i]>0) sma=min(sma,b[i]);
    }

    if(sma==n){
        cout<<str[0]<<endl;
    }
    else if(sma==1){
        cout<<-1<<endl;
    }
    else{   
         int result[27]={0};
         int result2[27]={0};
         bool res=true;
         for(int i=0;i<26;i++){
              
              if(arr[i]%sma==0) result[i]=arr[i]/sma;
              else{
                 res=false;
                 break;
              }

              if(b[i]%sma==0) result2[i]=b[i]/sma;
              else{
                 res=false;
                 break;
              }
         }

         if(res){
             
             for(int i=0;i<n;i++){
                if(str[i]>='a' && str[i]<='z' && result[str[i]-'a']>0){
                    cout<<str[i];
                    result[str[i]-'a']--;
                }
                if(str[i]>='A' && str[i]<='Z' && result2[str[i]-'A']>0){
                    cout<<str[i];
                    result[str[i]-'A']--;
                }
             }
             cout<<endl;
         }
         else cout<<-1<<endl;


         
    }


    return 0;
}