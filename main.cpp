#include <iostream>

long long gcd(long long a, long long b){
    if(b==0)
        return a;
    return gcd(b, a%b);
}

long long mul(long long a, long long b, long long m){
    if(b==1)
        return a;
    if(b%2==0){
        long long t = mul(a, b/2, m);
        return (2 * t) % m;
    }
    return (mul(a, b-1, m) + a) % m;
}

long long pows(long long a, long long b, long long m){
    if(b==0)
        return 1;
    if(b%2==0){
        long long t = pows(a, b/2, m);
        return mul(t , t, m) % m;
    }
    return ( mul(pows(a, b-1, m) , a, m)) % m;
}
bool ferma(long long x){
    if(x == 2)
        return true;
    srand(time(NULL));
    for(int i=0;i<100;i++){
        long long a = (rand() % (x - 2)) + 2;
        if (gcd(a, x) != 1)
            return false;
        if( pows(a, x-1, x) != 1)
            return false;
    }
    return true;
}

long long B(long long n){
    long long Firstval = (n-1)*n/2 + 1, sum = 0;
    if (ferma(Firstval)){
        if(n%2==0){
            if((ferma(Firstval-n+2) && (ferma(Firstval + 2) || ferma(Firstval - 2*n +4))) ||
                    (ferma(Firstval+n) && ferma(Firstval+2*n+2)))
                sum+=Firstval;
        } else {
            if((ferma(Firstval+n+1) && (ferma(Firstval+2*n +3) || ferma(Firstval+2))) ||
                    (ferma(Firstval-n+1) && ferma(Firstval - 2*n + 4)))
                sum+=Firstval;
        }
    } else if(ferma(Firstval+1)){
        if(n%2 == 0){
            if((ferma(Firstval+1-n) && ferma(Firstval+1 - 2*n + 2)) ||
                    (ferma(Firstval+1 - n + 2) && (ferma(Firstval+1 - 2*n + 4) || ferma(Firstval+1 + 2))) ||
                    (ferma(Firstval+1 + n) && (ferma(Firstval+1+2*n) || ferma(Firstval+1 + 2*n + 2))))
                    sum+=Firstval+1;
        } else{
            if((ferma(Firstval+1 - n + 1) && (ferma(Firstval+1 -2*n +2) || ferma(Firstval+1 - 2*n + 4))) ||
                    (ferma(Firstval+1 +n - 1) && ferma(Firstval+1 +2*n)) ||
                    (ferma(Firstval+1 + n + 1) && (ferma(Firstval+1 + 2*n + 2) || ferma(Firstval + 1 + 2))))
                sum+=Firstval+1;
        }
    }
    std::cout << sum << std::endl;
    for(long long i = Firstval + 2; i < Firstval+n - 4;i+=2) {
        if (i % 2 == 0)
            i++;
        if (ferma(i)) {
            if (n % 2 == 0) {
                if (ferma(i - n)) {
                    if (ferma(i - 2 * n + 2) || ferma(i - 2) || ferma(i-n+2) || ferma(i+n)) {
                        sum += i;
                        std::cout << i << " 1 ";
                    }
                } else if (ferma(i - n + 2)) {
                    if (ferma(i - 2 * n + 4) || ferma(i + 2) || ferma(i+n)) {
                        sum += i;
                        std::cout << i << " 2 ";
                    }
                } else if (ferma(i + n)) {
                    if (ferma(i + 2 * n) || ferma(i + 2 * n + 2)) {
                        sum += i;
                        std::cout << i << " 3\n ";
                    }
                }
            } else {
                if (ferma(i - n + 1)) {
                    if (ferma(i - 2 * n + 2) || ferma(i - 2 * n + 4) || ferma(i+n-1) || ferma(i+n+1)) {
                        sum += i;
                        std::cout << i << " 4 \n";
                    }
                } else if (ferma(i + n - 1)) {
                    if (ferma(i + 2 * n) || ferma(i - 2) || ferma(i+n+1)) {
                        sum += i;
                        std::cout << i << " 5 \n";
                    }
                } else if (ferma(i + n + 1)) {
                    if (ferma(i + 2 * n + 2) || ferma(i + 2)) {
                        sum += i;
                        std::cout << i << " 6 \n";
                    }
                }


            }
        }
    }

    return sum;
}

int main() {
    std::cout << std::endl << B(10001) ;
    return 0;
}
