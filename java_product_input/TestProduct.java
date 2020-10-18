package Phongtest1;

import java.util.Scanner;

public class TestProduct {
    public static void main(String[] args) {

        int switchnumber;Shop shop = new Shop();
        Scanner scanner = new Scanner(System.in);
        while (true){ //sau khi chay xong case thi se chay lai de nhap tiep
            System.out.println("+------------------------------------------+");
            System.out.println("1. Them san pham: ");
            System.out.println("2. Xoa san pham: ");
            System.out.println("3. Xem san pham va trung binh danh gia: ");
            System.out.println("4. Kiem tra san pham: ");
            System.out.println("5. Thoat");
            System.out.println("+------------------------------------------+");

            System.out.print("Nhap so ma ban muon chon: "); switchnumber = scanner.nextInt();
            switch (switchnumber){
                case 1: shop.addProduct(); break;
                case 2: shop.removeProduct(); break;
                case 3: shop.iterateProductList(); break;
                case 4: shop.searchProduct(); break;
                case 5: System.exit(1);
                default: System.out.println("Nhap sai, xin moi nhap lai"); break;
            }
        }




    }
}

