//CN-7 ----Hammminng code
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
int hum[15000];
int cheksum[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int binary[16];
int decimalTObinary(int n,int decimal){
	int i;
	for(i=0;i<n;i++){
		binary[i]=decimal%2;
		decimal/=2;
	}
	return 0;
}
int power(int j){
	int i,x=2;
	if(j==0){
		return 1;
	}
	else{
		for(i=1;i<j;i++){     x*=2;	}
		return x;
	}
	return 0 ;
}
int XOR(int n,int A[]){
	int i;
	for(i=0;i<n;i++){
		if(A[i]==0){
			if(cheksum[i]==0){
				cheksum[i]=0;
			}
			else{
				cheksum[i]=1;
			}
		}
		else{
			if(cheksum[i]==0){
				cheksum[i]=1;
			}
			else{
				cheksum[i]=0;
			}
		}
	}
}
int chechsum_fun(int n,int m,int hum[]){
	int i,j=0;
	for(i=1;i<=n+m;i++){
		if(i!=power(j)){
			if(hum[i]==1){
				decimalTObinary(n,i);
				XOR(n,binary);
			}
		}else{	j++; }
	}
}
int Hamming_Array(int m,int  Array[],int n){
	int i,j=0,x=2,z=0,u;
	x=1;
	for(i=1;i<=m+n;i++){
		if(i==x){
			j++;
			x=power(j);
			hum[i]=5;
		}	    
		else{
			hum[i]=Array[z];
			z++;
		}
		if(z>m){
			break;
		}
	}
	printf("\n\nAfter the Genartion of Hamming array is  \n");
	for(i=n+m;i>=1;i--){
		printf("%d",hum[i]);
	}
	return 0;
}
int check_Smaller(int m){
	int i=1,n=0,x=2,j;
	while(i==1){
		for(j=1;j<=n;j++){     x*=2;	}
		n++;
		if(x>=m+n+1){
			i=0;
			break;
		}
		x=2;
	}
	return n;
}
int main(){
	int i=0,m,ch=0,Size_of_bit,parity,n;
	int message[15000],reciver[15000],reciver_bit;
	
	//clrscr();
	printf("Code by utsav vachhani(uv)");
	printf("\nWhat is Size of Your Message:");
	scanf("%d",&Size_of_bit);
	if(Size_of_bit>15000){
		printf("\nMessage is higher  than 15000 .");
		return 0;
	}
    printf("\nEnter message:");
	m=Size_of_bit;
	for(i=0;i<Size_of_bit;i++){
        scanf("%d",&message[i]);
    }
	printf("\nYour Enter Message from sender side is : \n");
	for(i=Size_of_bit-1;i>=0;i--){
		printf("%d",message[i]);
	}

	n=check_Smaller(Size_of_bit);
	printf("\nn=%d",n);

	Hamming_Array(m,message,n);
	//find the Hamming code
	chechsum_fun(n,m,hum);
	printf("\nHammming code is : ");
	for(i=n-1;i>=0;i--){
		printf("%d",cheksum[i]);
	}

	printf("\n---------------------------------------------------------------------------------------");
	printf("\nHow many bit Recive at Reciver side :");
	scanf("%d",&reciver_bit);
	if(reciver_bit>15000){
		printf("\nMessage is higher  than 15000 .");
		return 0;
	}
    for(i=0;i<reciver_bit;i++){
        scanf("%d",&reciver[i]);
    }
	printf("Your Enter Message from reciver side is : \n");
	for(i=reciver_bit-1;i>=0;i--){
		printf("%d",reciver[i]);
	}
	n=check_Smaller(reciver_bit);
	printf("\nn=%d",n);
	Hamming_Array(reciver_bit,reciver,n);

	chechsum_fun(n,m,hum);
	printf("\n\nHammming code is : ");
	ch=0;
	for(i=n-1;i>=0;i--){
		printf("%d",cheksum[i]);
		if(cheksum[i]!=0){
			ch+=1;
		}
	}

	printf("\n\n-------------------------");
	if(ch==0)
		printf("\n|\tNo Error!!!\t|");
	else
		printf("\n|\t  Error!!! \t|");
	

	printf("\n-------------------------");
	return -1;
}