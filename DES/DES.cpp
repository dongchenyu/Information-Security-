#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
int key1[56]={
    57, 49, 41, 33, 25, 17,  9,
     1, 58, 50, 42, 34, 26, 18,
    10,  2, 59, 51, 43, 35, 27,
    19, 11,  3, 60, 52, 44, 36,
    63, 55, 47, 39, 31, 23, 15,
     7, 62, 54, 46, 38, 30, 22,
    14,  6, 61, 53, 45, 37, 29,
    21, 13,  5, 28, 20, 12,  4
};
int key2[48]={
    14,17,11,24,1,5,
    3,28,15,6,21,10,
    23,19,12,4,26,8,
    16,7,27,20,13,2,
    41,52,31,37,47,55,
    30,40,51,45,33,48,
    44,49,39,56,34,53,
    46,42,50,36,29,32
};
int IP1[64]={
    58,50,42,34,26,18,10,2,
    60,52,44,36,28,20,12,4,
    62,54,46,38,30,22,14,6,
    64,56,48,40,32,24,16,8,
    57,49,41,33,25,17,9,1,
    59,51,43,35,27,19,11,3,
    61,53,45,37,29,21,13,5,
    63,55,47,39,31,23,15,7
};
int E1[48]={
    32,1,2,3,4,5,
    4,5,6,7,8,9,
    8,9,10,11,12,13,
    12,13,14,15,16,17,
    16,17,18,19,20,21,
    20,21,22,23,24,25,
    24,25,26,27,28,29,
    28,29,30,31,32,1,
};
int S1[4][16]={
    14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7,
    0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8,
    4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0,
    15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13
};
int S2[4][16]={
    15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10,
    3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5,
    0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15,
    13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9
};
int S3[4][16]={
    10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8,
    13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1,
    13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7,
    1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12
};
int S4[4][16]={
    7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15,
    13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9,
    10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4,
    3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14
};
int S5[4][16]={
    2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9,
    14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6,
    4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14,
    11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3,
};
int S6[4][16]={
    12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11,
    10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8,
    9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6,
    4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13
};
int S7[4][16]={
    4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1,
    13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6,
    1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2,
    6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12
};
int S8[4][16]={
    13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7,
      1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2,
      7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8,
      2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11
};
int P[32]={
    16,7,20,21,
    29,12,28,17,
    1,15,23,26,
    5,18,31,10,
    2,8,24,14,
    32,27,3,9,
    19,13,30,6,
    22,11,4,25
};
int IP2[64]={
    40,8,48,16,56,24,64,32,
    39,7,47,15,55,23,63,31,
    38,6,46,14,54,22,62,30,
    37,5,45,13,53,21,61,29,
    36,4,44,12,52,20,60,28,
    35,3,43,11,51,19,59,27,
    34,2,42,10,50,18,58,26,
    33,1,41,9,49,17,57,25,
};
string hex_[16]={"0000","0001","0010","0011","0100",
"0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};
char hex2[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
vector<string>C;
vector<string>D;
vector<string>K0;
vector<string>K;
vector<string>L;
vector<string>R;
string htob(string s){
    int len=s.size();
    string result;
    for(int i=0;i<len;i++){
        if(s[i]>='0'&&s[i]<='9'){
            result+=hex_[s[i]-'0'];
        }
        else{
            result+=hex_[s[i]-'A'+10];
        }
    }
    return result;
}
//64 to 56
string key_change(string key){
    int len=key.size();
    string result;
    for(int i=0;i<56;i++){
        char c=key[key1[i]-1];
        result.push_back(c);
    }
    return result;
}
string key_change2(string key){
    int len=key.size();
    string result;
    for(int i=0;i<48;i++){
        char c=key[key2[i]-1];
        result.push_back(c);
    }
    return result;
}
string IP_change(string IP){
    string result;
    int len=IP.size();
    for(int i=0;i<len;i++){
        char c=IP[IP1[i]-1];
        result.push_back(c);
    }
    return result;
}
string E(string R){
    string result;
    int len=R.size();
    for(int i=0;i<48;i++){
        char c=R[E1[i]-1];
        result.push_back(c);
    }
    return result;
}
int left_shift[16]={1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};
string move(string s,int shift){
    string result;
    int len=s.size();
    string temp=s.substr(0,shift);
    for(int i=shift;i<len;i++){
        result.push_back(s[i]);
    }
    result+=temp;
    return result;
}
string XOR_(string a,string b){
    string result;
    int len=a.size();
    for(int i=0;i<len;i++){
        if(a[i]==b[i]){
            result.push_back('0');
        }
        else{
            result.push_back('1');
        }
    }
    return result;
}
string S(string s){
    string result;
    for(int i=0;i<8;i++){
        string temp=s.substr(i*6,(i+1)*6);
        int row=(temp[0]-'0')*2+(temp[5]-'0');
        int column=(temp[1]-'0')*8+(temp[2]-'0')*4+(temp[3]-'0')*2+(temp[4]-'0');
        int target;
        if(i==0){
            target=S1[row][column];
        }
        if(i==1){
            target=S2[row][column];
        }
        if(i==2){
            target=S3[row][column];
        }
        if(i==3){
            target=S4[row][column];
        }
        if(i==4){
            target=S5[row][column];
        }
        if(i==5){
            target=S6[row][column];
        }
        if(i==6){
            target=S7[row][column];
        }
        if(i==7){
            target=S8[row][column];
        }
        result+=hex_[target];
    }
    return result;
}
string P_(string s){
    string result;
    for(int i=0;i<32;i++){
        char c=s[P[i]-1];
        result.push_back(c);
    }
    return result;
}
string f(string R0,string K1){
    string temp=E(R0);
    string temp1=XOR_(K1,temp);
    string temp2=S(temp1);
    string result=P_(temp2);
    return result;
}
string IP_2(string str){
    string result;
    for(int i=0;i<64;i++){
        result.push_back(str[IP2[i]-1]);
    }
    return result;
}
string bintohex(string str){
    string result;
    for(int i=0;i<16;i++){
        string temp=str.substr(i*4,i*4+4);
        int target=(temp[0]-'0')*8+(temp[1]-'0')*4+(temp[2]-'0')*2+(temp[3]-'0');
        result.push_back(hex2[target]);
    }
    return result;
}
int main(){
    string input;
    string key;
    cin>>input>>key;
    string bin_input=htob(input);
    string bin_key=htob(key);
    string key_1=key_change(bin_key);
    string C0=key_1.substr(0,28);
    string D0=key_1.substr(28,28);
    C.push_back(C0);
    D.push_back(D0);
    for(int i=0;i<16;i++){
        string c,d;
        c=move(C[i],left_shift[i]);
        d=move(D[i],left_shift[i]);
        C.push_back(c);
        D.push_back(d);
    }
    for(int i=0;i<17;i++){
        string temp=C[i]+D[i];
        K0.push_back(temp);
    }
    for(int i=0;i<17;i++){
        string temp=key_change2(K0[i]);
        K.push_back(temp);
    }
    string IP=IP_change(bin_input);
    string L0=IP.substr(0,32);
    string R0=IP.substr(32,32);
    L.push_back(L0);
    R.push_back(R0);
    for(int i=1;i<=16;i++){
        string templ=R[i-1];
        L.push_back(templ);
        string tempr=XOR_(L[i-1],f(R[i-1],K[i]));
        R.push_back(tempr);
    }
    string test=R[16]+L[16];
    test=IP_2(test);
    string final=bintohex(test);
    cout<<final<<endl;
}