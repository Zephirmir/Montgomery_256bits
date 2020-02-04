#include <iostream>
#include <math.h>
#include <stdint.h>

#define UINT_MAX 4294967295
// Numbers used for the tests : a = 64748982491068704272763033717990044173421824164906418541262075997032515608547
//                              b = 107254444806228738109683210760848215956850094984599455133780233417351108742550
//                              n = 108467768954592239533233402010693135244041837596387224299664103227858614256363
unsigned int calc_r(unsigned int x);

unsigned int montgomery(unsigned int* a, unsigned int* b,unsigned int *c, unsigned int* n, unsigned int *r, unsigned int* v);
unsigned int add(unsigned int* a,unsigned int* b,unsigned int *c);
unsigned int add_512(unsigned int* a,unsigned int* b, unsigned int* c);
unsigned int add_word (unsigned int a, unsigned int b, unsigned int carry, unsigned int * ret);
unsigned int add_mod(unsigned int* a, unsigned int* b, unsigned int* c, unsigned int* n);
unsigned int sub_word(unsigned int a, unsigned int b, unsigned int * ret);
unsigned int sub(unsigned int* a, unsigned int* b, unsigned int* c);
unsigned int compare_256(unsigned int* a, unsigned int* b);
unsigned int multiplication(unsigned int* a, unsigned int* b, unsigned int* c);

int main() {

    /*   TEST OF FUNCTION ADD_WORD
    unsigned int a,b;
    unsigned int ret[2];
    a = 4294967295;
    b = 2;
    add_word(a,b,0,ret);
    std::cout << "result : " << ret[0] << "\n" << "carry_out : " << ret[1];
*/


    /* TEST OF FUNCTION ADD
    unsigned int a[8],b[8],c[8];
    unsigned int carry_out;


    a[0] = 3112935395 ;
    a[1] = 4261025161 ;
    a[2] = 3679832726 ;
    a[3] = 3229666031 ;
    a[4] = 3221220049 ;
    a[5] = 3622841442 ;
    a[6] = 284506932 ;
    a[7] = 2401673241 ;

    b[0] =  3322924438 ;
    b[1] =  3855290132 ;
    b[2] =  793226570  ;
    b[3] =  321933644  ;
    b[4] =  533719443  ;
    b[5] =  1858486040 ;
    b[6] =  2741400005 ;
    b[7] =  3978288463 ;
    carry_out = add(a,b,c);
    for (int i = 0; i <= 7; i++){
        std::cout << c[7-i] << " ";
    }
    std::cout << "\n" << carry_out;
    */

    /* TEST OF FUNCTION SUB_WORD
    unsigned int a,b;
    unsigned int ret[2];
    a = 56;
    b = 96;
    sub_word(a,b,ret);
    std::cout << " result :  " << ret[0] << "\n carry : " << ret[1];
    */

    /*TEST OF FUNCTION SUB
    unsigned int a[8],b[8],c[8];
    a[0] = 3112935395 ;
    a[1] = 4261025161 ;
    a[2] = 3679832726 ;
    a[3] = 3229666031 ;
    a[4] = 3221220049 ;
    a[5] = 3622841442 ;
    a[6] = 284506932 ;
    a[7] = 2401673241 ;

    b[0] =  3322924438 ;
    b[1] =  3855290132 ;
    b[2] =  793226570  ;
    b[3] =  321933644  ;
    b[4] =  533719443  ;
    b[5] =  1858486040 ;
    b[6] =  2741400005 ;
    b[7] =  3978288463 ;

    sub(b,a,c);
    for (int i = 0; i <= 7; i++){
        std::cout << c[7-i] << " ";
    }
    */

    /*TEST OF FUNCTION add_mod
   unsigned int a[8],b[8],c[8],n[8],d[8],temp[8];
   a[0] = 1 ;
   a[1] = 0 ;
   a[2] = 0 ;
   a[3] = 0 ;
   a[4] = 0 ;
   a[5] = 0 ;
   a[6] = 0 ;
   a[7] = 0 ;


    b[0] =  2346746603 ;
    b[1] =  97752548 ;
    b[2] =  1212639141  ;
    b[3] =  1605029854  ;
    b[4] =  2462548362  ;
    b[5] =  2597077587 ;
    b[6] =  2478869136 ;
    b[7] =  4023293157 ;

    n[0] =  2346746603 ;
    n[1] =  97752548 ;
    n[2] =  1212639141  ;
    n[3] =  1605029854  ;
    n[4] =  2462548362  ;
    n[5] =  2597077587 ;
    n[6] =  2478869136 ;
    n[7] =  4023293157 ;

   add_mod(b,a,c,n);
   for (int i = 0; i <= 7; i++){
       std::cout << c[7-i] << " " << 7-i << " ";

   }
   */

    /*TEST OF FUNCTION COMPARE
    unsigned int a[8],b[8];
    a[0] = 3112935395 ;
    a[1] = 4261025161 ;
    a[2] = 3679832726 ;
    a[3] = 3229666031 ;
    a[4] = 3221220049 ;
    a[5] = 3622841442 ;
    a[6] = 284506932 ;
    a[7] = 2401673241 ;

    b[0] =  3322924438 ;
    b[1] =  3855290132 ;
    b[2] =  793226570  ;
    b[3] =  321933644  ;
    b[4] =  533719443  ;
    b[5] =  1858486040 ;
    b[6] =  2741400005 ;
    b[7] =  3978288463 ;
    std::cout << compare_256(a,b);
    */

    /*TEST OF FUNCTION MULTIPLICATION
    unsigned int a[8],b[8],c[16];
    for (int i = 0; i <= 15; i++){
        c[i] = 0;
    }

    a[0] = 3112935395 ;
    a[1] = 4261025161 ;
    a[2] = 3679832726 ;
    a[3] = 3229666031 ;
    a[4] = 3221220049 ;
    a[5] = 3622841442 ;
    a[6] = 284506932 ;
    a[7] = 2401673241 ;

    b[0] =  3322924438 ;
    b[1] =  3855290132 ;
    b[2] =  793226570  ;
    b[3] =  321933644  ;
    b[4] =  533719443  ;
    b[5] =  1858486040 ;
    b[6] =  2741400005 ;
    b[7] =  3978288463 ;

    multiplication(a,b,c);
    for (int i = 0; i <= 15; i++){
        std::cout << 15-i << " : " << c[15-i] << "\n" ;

    }
*/
    //TEST OF FUNCTION MONTGOMERY

    return 0;
}


//function returning a-b in our representation, a should be bigger than b
unsigned int sub(unsigned int* a, unsigned int* b, unsigned int* c){
    unsigned int function_ret[2];
    unsigned int carry = 0;
    for (int i = 0; i <= 7; i++){
        sub_word(a[i],b[i]+ carry,function_ret);
        c[i] = function_ret[0];
        carry = function_ret[1];
    }
    return 0;
}
//function returning a-b
unsigned int sub_word(unsigned int a, unsigned int b, unsigned int *ret){
    unsigned int c;
 if (a < b){
     c = b-a;
     ret[0] = UINT_MAX - c +1;
     ret[1] = 1;
 }else {
     ret[0] = a-b;
     ret[1] = 0;
 }
 return 0;
}

//function that returns (a + b) mod n and places it into variable c. a and b are given mod n
unsigned int add_mod(unsigned int* a, unsigned int* b, unsigned int* c, unsigned int* n){
    unsigned int carry_out =0;
    unsigned int temp[8], temp2[8],temp3[8];
    for (int i =0;i <= 7; i++) temp[i] = UINT_MAX; // temp = 2**256
    carry_out = add(a,b,temp2);
    if (carry_out ==1){ // a+b is higher than n so the result is a+b-n and temp2 = a+b - 2**256
        sub(temp,n,temp3); // temp3 = 2**256 -n
        add(temp3,temp2 ,c); // c = temp + temp2 = a+b -2**256 + 2**256 - n = a + b - n
    } else { // a+b may be lower than n
        if (compare_256(temp2,n) == 1) { //n < a+b
            sub(temp2,n,c); // c = a + b - n
        } else if (compare_256(temp2,n) == 2) { //a+b < n
            for (int i =0;i <= 7; i++) c[i] = temp2[i];
        } else { // a+b = n
            for (int i =0;i <= 7; i++) c[i] = 0;
        }
    }
}



//function adding two 256 bits integers a,b and placing the result in integer c
unsigned int add(unsigned int* a,unsigned int* b, unsigned int* c){
    unsigned int function_ret[2];
    unsigned int carry = 0;
    for (int i = 0; i <= 7; i++){
        add_word(a[i],b[i],carry,function_ret);
        c[i] = function_ret[0];
        carry = function_ret[1];
    }

    return carry;
}

//function adding two 256 bits integers a,b and placing the result in integer c
unsigned int add_512(unsigned int* a,unsigned int* b, unsigned int* c){
    unsigned int function_ret[2];
    unsigned int carry = 0;
    for (int i = 0; i <= 15; i++){
        add_word(a[i],b[i],carry,function_ret);
        c[i] = function_ret[0];
        carry = function_ret[1];
    }

    return carry;
}


//function adding two unsigned int, returning the sum and the out carry if there is one.
unsigned int add_word (unsigned int a, unsigned int b, unsigned int carry, unsigned int * ret){
    unsigned int add_a_b;
    unsigned int carry_out = 0;

    if ((b > 0) && (a > UINT_MAX - b)){ /* `a + b` overflows */
        carry_out = 1;
        add_a_b =  a + b + carry ;
    }else {
        add_a_b = a+b;
        if ((add_a_b > 0) && (carry > UINT_MAX - add_a_b)) { /* a + b + carry overflows */
            carry_out = 1;
            add_a_b = add_a_b + carry ;
        } else {
            add_a_b += carry;
        }
    }
    ret[0] = add_a_b;
    ret[1] = carry_out;

    return 0;

}

//function comparing two 256 bits int, 0 : a = b | 1 : b < a | 2 : a < b
unsigned int compare_256(unsigned int* a, unsigned int* b){
    for (int i =0;i<= 7; i++){
        if (a[7-i]<b[7-i]) { // b is bigger, return 2
            return 2;
        } else if (b[7-i]<a[7-i]) { // a is bigger, return 1
            return 1;
        }
    }
    return 0; // if we get to this point, a=b so we return 0
}

/*
//Function returning the first power of 2 above x
unsigned int calc_r(unsigned int x){
    bool end = false;
    unsigned int i = 0;
    while (!end) {
        if ( pow(2,i) < x) {
            i++;
        }else {
            end = true;
        }
    }
    return i;
}
*/

//Extended Euclidean algorithm
unsigned int calc_inv(unsigned int b,unsigned int n){
    unsigned int n0,b0,t0,t,q,r;
    int temp;
    n0 = n;
    b0 = b;
    t0 = 0;
    t = 1;
    q = floor(n0/b0);
    r = n0 - q*b0;
    while (r > 0){
        temp = t0 - q*t;
        if (temp >=  0) {
            temp = temp % n;
        }else {
            temp = n - (-temp % n);
        }
        t0 = t;
        t = temp;
        n0 = b0;
        b0 = r;
        q = floor(n0/b0);
        r = n0 - q*b0;
    }

    return t;
}

//function calculating a*b and storing it in c
unsigned int multiplication(unsigned int* a, unsigned int* b, unsigned int* c){
    unsigned long long int temporary_64;
    unsigned int uint32;
    unsigned int operande;
    unsigned int function_ret[2];
    bool end = false;
    unsigned int k = 0;
    for (int i = 0; i<= 7; i++){
        for (int j = 0; j<= 7; j++){

            temporary_64 =(uint64_t)a[i] * (uint64_t)b[j];

            //handling the 32 most significant bits of the result
            uint32 = temporary_64  >> 32;
            add_word(uint32 ,c[i+j+1],0,function_ret );
            if (function_ret[1] == 1){ // there is overflow
                k = 1;
                end = false;
                c[i+j+1] = function_ret[0];
                while (!end){ // while overflow occurs we spread it
                    add_word(0 ,c[i+j+k+1],1,function_ret );
                    c[i+j+k+1] = function_ret[0];
                    k++;
                    if (function_ret[1] == 0) end = true;
                }
            }else {
                c[i+j+1] = function_ret[0];
            }

            //handling the 32 least significant bits of the result
            uint32 = temporary_64  & 0b0000000000000000000000000000000011111111111111111111111111111111 ;

            add_word(uint32 ,c[i+j],0,function_ret );
            operande = c[i+j];
            //std::cout  << function_ret[0] << "\n";
            if (function_ret[1] == 1){ // overflow
                k = 1;
                end = false;
                c[i+j] = function_ret[0] ;
                while (!end){ // while overflow occurs we spread it
                    add_word(0 ,c[i+j+k],1,function_ret );
                    c[i+j+k] = function_ret[0];
                    k++;
                    if (function_ret[1] == 0) end = true;
                }
            }else {
                c[i+j] = function_ret[0];
            }
        }
    }
    return 0;

}

// application of the montgomery algorithm with our representation of great numbers
unsigned int montgomery(unsigned int* a, unsigned int* b,unsigned int *c, unsigned int* n, unsigned int *r, unsigned int* v){
    unsigned int s[16],temp[16],temp2[16],t[8],m[16],u[8];

    multiplication(a,b,s); // s = a*b
    multiplication(s,v,temp);
    for (int i = 0; i<= 7; i++) t[i] = temp[i]; // t = s*v mod r
    multiplication(t,n,temp2);
    add_512(temp2,s,m); //m = s + (t*n)
    for (int i = 8; i<= 15; i++) u[8-i] = m[i]; // u = m/r

    if (compare_256(u,n) == 2) { // u < n
        for (int i = 0; i<= 7; i++) c[i] = u[i];
    } else { // u >= n
        sub(u,n,c);
    }
}