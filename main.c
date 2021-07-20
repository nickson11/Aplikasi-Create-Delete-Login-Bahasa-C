#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int main(){
    char user[20],pass[20],a[20],b[]=".txt";
    char *c,*p;
    int i=1;
    struct dirent *de;
    FILE *fl;
    sini:
    system("cls");
    puts("===LOGIN===");
    printf("Username : ");scanf("%s",user);
    printf("Password : ");scanf("%s",pass);
    if(strcmp(user,"admin")==0 && strcmp(pass,"ganteng")==0){
        printf("Selamat Datang admin!\n");
        system("pause");
        int pilih;
        char mana;
        do{
            system("cls");
            puts("===MENU===");
            puts("1. Menu Satu (Lihat, Update, Delete TXT)");
            puts("2. Menu Dua (Buat TXT)");
            puts("3. Logout");
            puts("4. Exit");
            printf("Pilih Menu : ");scanf("%d",&pilih);
            switch(pilih){
                case 1:
                    system("cls");
                    DIR *dr=opendir(".");
                    if(dr==NULL){
                        puts("Tidak ada file dalam folder");
                    }
                    puts("===Menu Satu Lihat, Update, Delete TXT===");
                    while((de=readdir(dr))!=NULL){
                        p=strstr(de->d_name,b);
                        if(p!=NULL){
                            printf("%d. %s\n",i,de->d_name);
                            i++;
                        }
                    }
                    i=1;

                    closedir(dr);
                    system("pause");
                    break;
                case 2:
                    system("cls");
                    puts("===Menu Dua Buat TXT===");
                    printf("Masukkan Nama File : ");scanf("%s",a);
                    c=strstr(a,b);
                    if(c!=NULL){
                        fl=fopen(a,"a");
                        fclose(fl);
                        printf("Sukses membuat file %s\n",a);
                    }
                    else{
                        printf("Gagal membuat file %s\n",a);
                    }
                    system("pause");
                    break;
                case 3:
                    system("cls");
                    puts("Admin berhasil logout!");
                    system("pause");
                    goto sini;
                    break;
            }
        }
        while(pilih!=4);
    }
    else{
         printf("Username atau Password tidak sesuai!\n");
         system("pause");
         goto sini;
    }
    return 0;
}
