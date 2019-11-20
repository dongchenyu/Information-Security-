#include<iostream>
#include<cstring>
#include<vector>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <math.h>
using namespace std;
void char_to_bin(char c,int s[],int start){
    int num=c;
    vector<int>v;
    while(num>0){
        int now=num%2;
        num/=2;
        v.push_back(now);
    }
    int len=v.size();
    int fill=8-len;
    for(int i=0;i<fill;i++){
        v.push_back(0);
    }
    for(int i=0;i<8;i++){
        s[start]=v[7-i];
        start++;
    }
}
int length_to_bin(int length,int tail[]){
    vector<int>v;
    int temp=length;
    while(temp>0){
        int add=temp%2;
        temp/=2;
        v.push_back(add);
    }
    int len=v.size();
    int front;
    if(len%8==0){
        front=0;
    }
    else{
        front=8-(len%8);
    }
    for(int i=0;i<len;i++){
        tail[i+front]=v[len-i-1];
    }
    return front+len;
}

void div_512_to_16(int a[],unsigned int b[]){
    for(int i=0;i<16;i++){
        unsigned int temp[4]={0};
        for(int j=0;j<4;j++){
            for(int k=0;k<8;k++){
                temp[j]+=a[i*32+8*j+k]*pow(2,7-k);
            }
            b[i]+=temp[j]<<(8*j);
        }
    }
}
unsigned int F(unsigned int b,unsigned int c,unsigned int d){
    return (b & c)|(~b & d);
}
unsigned int G(unsigned int b,unsigned int c,unsigned int d){
    return (b & d)|(c & ~d);
}
unsigned int H(unsigned int b,unsigned int c,unsigned int d){
    return (b ^ c ^ d);
}
unsigned int I(unsigned int b,unsigned int c,unsigned int d){
    return (c ^ (b | ~d));
}
unsigned int CLS(unsigned int a, int s){
    unsigned int temp1=a << s;
    unsigned int temp2=a >> (32-s);
    return ((a << s) | (a >> (32-s)));
}
void FF(unsigned int &a,unsigned int b,unsigned int c,unsigned int d,unsigned int Mj,unsigned int s,unsigned int ti){
    unsigned int temp=a+F(b,c,d)+Mj+ti;
    a=b+CLS(temp,s);
    
}
void GG(unsigned int &a,unsigned int b,unsigned int c,unsigned int d,unsigned int Mj,unsigned int s,unsigned int ti){
    unsigned int temp=a+G(b,c,d)+Mj+ti;
    a=b+CLS(temp,s);
    
}
void HH(unsigned int &a,unsigned int b,unsigned int c,unsigned int d,unsigned int Mj,unsigned int s,unsigned int ti){
    unsigned int temp=a+H(b,c,d)+Mj+ti;
    a=b+CLS(temp,s);
    
}
void II(unsigned int &a,unsigned int b,unsigned int c,unsigned int d,unsigned int Mj,unsigned int s,unsigned int ti){
    unsigned int temp=a+I(b,c,d)+Mj+ti;
    a=b+CLS(temp,s);
    
}
unsigned int* MD5(unsigned int MD[],unsigned int X[]){
    unsigned int A=MD[0];
    unsigned int B=MD[1];
    unsigned int C=MD[2];
    unsigned int D=MD[3];
    unsigned int a,b,c,d;
    a=A;
    b=B;
    c=C;
    d=D;
    FF(a,b,c,d,X[0],7,0xd76aa478);
    FF(d,a,b,c,X[1],12,0xe8c7b756);
    FF(c,d,a,b,X[2],17,0x242070db);
    FF(b,c,d,a,X[3],22,0xc1bdceee);
    FF(a,b,c,d,X[4],7,0xf57c0faf);
    FF(d,a,b,c,X[5],12,0x4787c62a);
    FF(c,d,a,b,X[6],17,0xa8304613);
    FF(b,c,d,a,X[7],22,0xfd469501);
    FF(a,b,c,d,X[8],7,0x698098d8);
    FF(d,a,b,c,X[9],12,0x8b44f7af);
    FF(c,d,a,b,X[10],17,0xffff5bb1);
    FF(b,c,d,a,X[11],22,0x895cd7be);
    FF(a,b,c,d,X[12],7,0x6b901122);
    FF(d,a,b,c,X[13],12,0xfd987193);
    FF(c,d,a,b,X[14],17,0xa679438e);
    FF(b,c,d,a,X[15],22,0x49b40821);
    GG(a,b,c,d,X[1],5,0xf61e2562);
    GG(d,a,b,c,X[6],9,0xc040b340);
    GG(c,d,a,b,X[11],14,0x265e5a51);
    GG(b,c,d,a,X[0],20,0xe9b6c7aa);
    GG(a,b,c,d,X[5],5,0xd62f105d);
    GG(d,a,b,c,X[10],9,0x02441453);
    GG(c,d,a,b,X[15],14,0xd8a1e681);
    GG(b,c,d,a,X[4],20,0xe7d3fbc8);
    GG(a,b,c,d,X[9],5,0x21e1cde6);
    GG(d,a,b,c,X[14],9,0xc33707d6);
    GG(c,d,a,b,X[3],14,0xf4d50d87);
    GG(b,c,d,a,X[8],20,0x455a14ed);
    GG(a,b,c,d,X[13],5,0xa9e3e905);
    GG(d,a,b,c,X[2],9,0xfcefa3f8);
    GG(c,d,a,b,X[7],14,0x676f02d9);
    GG(b,c,d,a,X[12],20,0x8d2a4c8a);
    HH(a,b,c,d,X[5],4,0xfffa3942);
    HH(d,a,b,c,X[8],11,0x8771f681);
    HH(c,d,a,b,X[11],16,0x6d9d6122);
    HH(b,c,d,a,X[14],23,0xfde5380c);
    HH(a,b,c,d,X[1],4,0xa4beea44);
    HH(d,a,b,c,X[4],11,0x4bdecfa9);
    HH(c,d,a,b,X[7],16,0xf6bb4b60);
    HH(b,c,d,a,X[10],23,0xbebfbc70);
    HH(a,b,c,d,X[13],4,0x289b7ec6);
    HH(d,a,b,c,X[0],11,0xeaa127fa);
    HH(c,d,a,b,X[3],16,0xd4ef3085);
    HH(b,c,d,a,X[6],23,0x04881d05);
    HH(a,b,c,d,X[9],4,0xd9d4d039);
    HH(d,a,b,c,X[12],11,0xe6db99e5);
    HH(c,d,a,b,X[15],16,0x1fa27cf8);
    HH(b,c,d,a,X[2],23,0xc4ac5665);
    II(a,b,c,d,X[0],6,0xf4292244);
    II(d,a,b,c,X[7],10,0x432aff97);
    II(c,d,a,b,X[14],15,0xab9423a7);
    II(b,c,d,a,X[5],21,0xfc93a039);
    II(a,b,c,d,X[12],6,0x655b59c3);
    II(d,a,b,c,X[3],10,0x8f0ccc92);
    II(c,d,a,b,X[10],15,0xffeff47d);
    II(b,c,d,a,X[1],21,0x85845dd1);
    II(a,b,c,d,X[8],6,0x6fa87e4f);
    II(d,a,b,c,X[15],10,0xfe2ce6e0);
    II(c,d,a,b,X[6],15,0xa3014314);
    II(b,c,d,a,X[13],21,0x4e0811a1);
    II(a,b,c,d,X[4],6,0xf7537e82);
    II(d,a,b,c,X[11],10,0xbd3af235);
    II(c,d,a,b,X[2],15,0x2ad7d2bb);
    II(b,c,d,a,X[9],21,0xeb86d391);
    A+=a;
    B+=b;
    C+=c;
    D+=d;
    MD[0]=A;
    MD[1]=B;
    MD[2]=C;
    MD[3]=D;
    return MD;
}

int main() {
    string str;
    cin>>str;
    int len=str.size();
    int bit_len = len * 8; 
    int left = bit_len%512;
    int fill;
    if(left < 448){
        fill=448 - left;
    }
    else{
        fill=448 - left + 512;
    }
    int tail[64] = {0};
    int width = length_to_bin(bit_len, tail);
    int group = (bit_len + fill + 64) / 512;
    unsigned int MD[4]={0x67452301,0xEFCDAB89,0x98BADCFE,0x10325476}; 
    for(int i = 0; i < group; i++){
        int Y[512] = {0};
        char c;
        int start = 0;
        int pos=0;
        while(start < 512 && pos<len){
            c = str[pos];
            char_to_bin(c, Y, start);
            start += 8;
            pos++;
        }
        if(start != 512 && start != 0){
            Y[start] = 1;
        }
        if(start == 0 && fill == 448){
            Y[start] = 1;
        }
        if(i == group - 1) {
            for(int k = 0; k < 64; k++) {
                Y[512 - 64 + k] = tail[k];
            }
        }
        unsigned int X[16] = {0};
        div_512_to_16(Y, X);
        MD5(MD, X);
    }
    unsigned char digit[16];
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            digit[i * 4 + j] = MD[i] >> (8 * j);
        }
    }
    for(int i = 0; i < 16; i++) {
       printf("%x", digit[i]);
    }
    cout << endl;
}