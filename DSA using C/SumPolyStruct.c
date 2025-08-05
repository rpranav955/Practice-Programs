#include <stdio.h>
#define MAXSIZE 20

typedef struct {
    float coeff;
    int exp;
} Term;

typedef struct{
    Term terms[MAXSIZE];
    int n;
} Polynomial;

void readPoly(Polynomial * a){
    printf("Enter the number of non-zero terms: ");
    scanf("%d",&a->n);

    for(int i = 0; i < a->n; i++){
        printf("Enter the coefficient: ");
        scanf("%f", &a->terms[i].coeff);
        printf("Enter the exponent of x: ");
        scanf("%d", &a->terms[i].exp);
    }
}

void printPoly(Polynomial a){
    for(int i = 0; i < a.n; i++){
        printf("%.2f x^%d",a.terms[i].coeff,a.terms[i].exp);
        if(i != a.n -1){
            printf(" + ");
        }
    }
    printf("\n");
}

Polynomial sum(Polynomial a, Polynomial b){
    Polynomial sum;
    sum.n = 0;
    int i = 0, j = 0;

    while(i < a.n && j < b.n){
        if(a.terms[i].exp == b.terms[j].exp){
            sum.terms[sum.n].exp = a.terms[i].exp;
            sum.terms[sum.n].coeff = a.terms[i].coeff + b.terms[j].coeff;
            i++; j++;sum.n++;
        }
        else if(a.terms[i].exp > b.terms[j].exp){
            sum.terms[sum.n++] = a.terms[i++];
        }
        else {
            sum.terms[sum.n++] = b.terms[j++];
        }
    }
    while(i < a.n){
            sum.terms[sum.n++] = a.terms[i++];
        }
    while(j < b.n){
        sum.terms[sum.n++] = b.terms[j++];
    }
    return sum;
}



int main(){
    
    Polynomial poly1,poly2,result;

    printf("\nEnter your first polynomial: \n");
    readPoly(&poly1);

    printf("\nEnter your second polynomial: \n");
    readPoly(&poly2);

    printf("\nSum of Polynomial 1 and 2: \n");
    printPoly(sum(poly1, poly2));
    
    return 0;
}
