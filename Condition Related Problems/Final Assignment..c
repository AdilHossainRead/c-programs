
#include <stdio.h>

int main() {
    char dept;
    float credits, feePerCredit = 0, discountRate = 0;
    float baseFee, afterDiscount, vat = 0, finalFee;

    printf("Enter Department (C/B/E): ");
    scanf(" %c", &dept);
    printf("Total Credit Taken: ");
    scanf("%f", &credits);

    if (dept == 'C' || dept == 'c') {
        feePerCredit = 1800;
        if (credits >= 15)
            discountRate = 0.10;
    } else if (dept == 'B' || dept == 'b') {
        feePerCredit = 1600;
        if (credits >= 18)
            discountRate = 0.08;
    } else if (dept == 'E' || dept == 'e') {
        feePerCredit = 1400;
        if (credits >= 20)
            discountRate = 0.12;
    } else {
        printf("Invalid Department!\n");
        return 1;
    }

    baseFee = credits * feePerCredit;
    afterDiscount = baseFee - (baseFee * discountRate);
    if (afterDiscount > 25000) {
        vat = afterDiscount * 0.05;
    }

    finalFee = afterDiscount + vat;
    printf("\nBase Fee: %.f Tk\n", baseFee);
    printf("After Discount: %.0f Tk\n", afterDiscount);
    printf("VAT (5%%): %.f Tk\n", vat);
    printf("Final Fee: %.f Tk\n", finalFee);

    return 0;
}
