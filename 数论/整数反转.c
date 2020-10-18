//整数反转
#include<stdio.h>
#include<stdlib.h>
// INT_MAX =2147483647
// INT_MIN =-2147483648
int reverse(int x) {
	    int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
int main(void) {
	int x;
	scanf("%d",&x);
	int res;
	res= reverse(x);
	printf("%d \n",res);
	return 0;
}
