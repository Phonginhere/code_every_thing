package Phongtest1;

import java.util.ArrayList;
import java.util.Scanner;

public class Shop {
    ArrayList<Product> ProductList = new ArrayList<>();
    Scanner scanner = new Scanner(System.in);

    void addProduct() {
        int number;

        Product product = new Product();
        do {
            System.out.println("Nhap ten san pham: ");
            product.Name = scanner.nextLine();
        } while (product.Name.length() == 0);
        do {
            System.out.println("Nhap thong tin san pham: ");
            product.Description = scanner.nextLine();
        } while (product.Description.length() == 0);
        do {
            System.out.println("Nhap so tien(0->100): ");
            product.Price = scanner.nextDouble();
        } while (!(product.Price > 0 && product.Price <= 100));
        do {
            System.out.println("Nhap so lan danh gia: ");
            number = scanner.nextInt();
        } while (number < 0);
        product.rate = new int[number]; //cap phat bo nho cho rate
        for (int i = 0; i < number; i++) {
            do {
                System.out.format("Nhap danh gia cua ban (tu 1 - 5) lan %d: ", i+1);
                product.rate[i] = scanner.nextInt();
            } while (!(1 <= product.rate[i] && product.rate[i] <= 5));
        }
        ProductList.add(product);
    }

    void removeProduct() {
        String name;
        if (ProductList.size() == 0) {
            System.out.println("Khong co san pham nao!!!");
        }else{
            do {
                System.out.print("Nhap ten san pham ma ban muon xoa: ");
                name = scanner.next();
            } while (name.length() == 0);
            for (Product p : ProductList) {
                if (p.Name.equals(name)) {
                    ProductList.remove(p);
                    System.out.println("Da xoa san pham: " + name);
                    break;
                } else {
                    System.out.println("ko the tim thay san pham: " + name);
                    break;
                }
            }
        }
    }

    void iterateProductList() {
        if (ProductList.size() == 0) {
            System.out.println("Khong co san pham nao!!!");
        } else {
            double AvgRate;
            for (Product p:ProductList) {
                p.viewInfo();
                AvgRate = 0;
                for (int i : p.rate) {
                    AvgRate += i;
                }
                System.out.println("trung binh cua san pham la: " + (AvgRate / p.rate.length));
            }
        }
    }

    void searchProduct() {
        int MinPrice, MaxPrice;
        if (ProductList.size() == 0) {
            System.out.println("Khong co san pham nao!!!");
        }else{
                do {
                    System.out.println("Nhap so tien thap nhat ");
                    MinPrice = scanner.nextInt();
                } while (!(0 < MinPrice && MinPrice <= 100));
                do {
                    System.out.println("Nhap so tien cao nhat ");
                    MaxPrice = scanner.nextInt();
                } while (!(0 < MaxPrice && MaxPrice <= 100));
            for(Product p:ProductList){
                if(p.Price > MinPrice && p.Price < MaxPrice){
                    p.viewInfo();
                }
            }
        }
    }
}
