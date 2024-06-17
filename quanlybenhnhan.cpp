#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct BenhNhan {
    char hoTen[100];
    char soCanCuoc[20];
    float tiLeBaoHiem; 
    float chiPhi; 
    float soTienPhaiNop; 
};
void nhapThongTinBenhNhan(struct BenhNhan *bn) {
    printf("Nhap ho ten benh nhan: ");
    fgets(bn->hoTen, sizeof(bn->hoTen), stdin);
    bn->hoTen[strcspn(bn->hoTen, "\n")] = '\0'; 
    printf("Nhap so can cuoc: ");
    fgets(bn->soCanCuoc, sizeof(bn->soCanCuoc), stdin);
    bn->soCanCuoc[strcspn(bn->soCanCuoc, "\n")] = '\0';
    printf("Nhap ti le huong bao hiem (%%): ");
    scanf("%f", &bn->tiLeBaoHiem);
    printf("Nhap chi phi: ");
    scanf("%f", &bn->chiPhi);
    while (getchar() != '\n');
}
void tinhTienPhaiNop(struct BenhNhan *bn) {
    bn->soTienPhaiNop = bn->chiPhi * (1 - bn->tiLeBaoHiem / 100);
}
void hienThiThongTinBenhNhan(struct BenhNhan bn) {
    printf("Ho ten: %s\n", bn.hoTen);
    printf("So can cuoc: %s\n", bn.soCanCuoc);
    printf("Ti le huong bao hiem: %.2f%%\n", bn.tiLeBaoHiem);
    printf("Chi phi: %.2f\n", bn.chiPhi);
    printf("So tien phai nop: %.2f\n", bn.soTienPhaiNop);
}
int main() {
    struct BenhNhan bn;
    nhapThongTinBenhNhan(&bn);
    tinhTienPhaiNop(&bn);
    printf("\nThong tin benh nhan:\n");
    hienThiThongTinBenhNhan(bn);

    return 0;
}
