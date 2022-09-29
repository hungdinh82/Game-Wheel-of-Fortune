#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include <stdlib.h>  

int dem = 0;

void clrscr() // Ham clear man hinh
{
    system("@cls||clear");
}

typedef struct 
{
    char Name[25];
    int Old;
    int Score[5];
} Game;

void khoidong(char s[], int *M, Game person[])
{   
    int sum = 0; 
    do
    {   
        sum = 0;  // sau moi lan nhap lai thi so dau cach tung nhap se duoc lam moi.
        printf("Hay nhap vao dong chu bi mat.\nDong chu bi mat co do dai nam trong doan [20,40]:\n");

        fflush(stdin);
        gets(s);
        for (int i = 0; i < strlen(s); i++)
        {
            if (*(s+i) == ' ')
            {
                sum ++;
            }
        }
        printf("%d\n%d\n", sum,strlen(s));
        if(strlen(s) < 20 || strlen(s) > 40 || sum > 0)
        {
            printf("Ban da nhap sai yeu cau nhap lai.\n");
        }
    
    }
    while (strlen(s) < 20 || strlen(s) > 40 || sum > 0); 

    do
    {
        printf("Hay nhap so luong nguoi choi:\n"); 
        scanf("%d", &*M);
        if(*M <= 0)
        {
            printf("Ban da nhap sai (nho hon 0) yeu cau nhap lai.\n");
        }
    }
    while (*M <= 0); 

    for (int i = 0; i < *M; i++)
    {
        printf("Nhap ten nguoi choi thu %d :\n", i+1);
        fflush(stdin);
        gets((person+i)->Name); 
    
        do
        {                                                      
            printf("Nhap tuoi cua nguoi choi thu %d :\n", i+1);
            scanf("%d", &((person+i)->Old));
            if(((person+i)->Old) < 0)
            {
                printf("Ban da nhap sai (nho hon 0]) yeu cau nhap lai.\n");
            }
        }
        while (((person+i)->Old) < 0);
    }
    
    printf("\tHo va ten               Tuoi\n");
    for (int i = 0; i < *M; i++)
    {    
        printf("\t%-24s%d\n", (person+i)->Name, (person+i)->Old);
    }
}

void trochoi(char s[], int *M, Game person[])
{   
    int luuso[61], diem[6];
    char doan[6], luu[61];
    char final[100];
    printf("BAT DAU TRO CHOI CHIEC NON KY LA:....\n");
    printf("O chu gom %d chu cai.\n\t", strlen(s));
    for (int i = 0; i < strlen(s); i++)
    {
        printf("*");
    }
    printf("\n");

    for (int i = 0; i < *M; i++)   // so nguoi choi
    {   
        printf("Nguoi choi thu %d: Ngai %s.\n", i+1, (person+i)->Name);
        
        for (int j = 0; j < 5; j++)  // 5 lan du doan
        {   
            int sum = 0;

            if (j == 4) //LAN THU 5 CHO RA MAM RIENG
            {   
                int cong = 0;          // dem xem co doan dung xau khong
                printf("Moi ngai du doan o chu bi mat :\n");
                fflush(stdin);
                gets((doan + j));

                for (int q = 0; q < strlen(s); q++)
                {
                    if (*(s + q) == (doan + j)[q] || *(s + q) + 32 == (doan + j)[q] || *(s + q) == (doan + j)[q] + 32)
                    {
                        cong++;
                    }
                }

                if (cong == strlen(s))
                {
                    printf("BAN DA DOAN DUNG O CHU BI MAT.\n");
                    ((person+i)->Score)[j] = 20;
                }
                if (cong != strlen(s))
                {
                    printf("Ban da doan sai o chu roi hahahaha.\n");
                    ((person+i)->Score)[j] = 0;
                }      
                printf("\n");

                for (int i = 0; i < strlen(s); i++) // xoa het bo nho khi sang nguoi choi moi
                {
                    luu[i] = 0;
                    luuso[i] = 0;
                    doan[i] = 0;
                }
                break;
            }
            
            printf("Moi ngai doan chu cai thu %d:\n", j+1);
            fflush(stdin);
            gets((doan + j));
            
            for (int k = 0; k < strlen(s); k++) //chay tu dau den cuoi sau s de kiem tra 
            {   
                if ( *(s + k) == *(doan + j) || *(s + k) + 32 == *(doan + j) || *(s + k) == *(doan + j) + 32 )
                {   
                    printf("%c", *(s + k));
                    luuso[k] = k;             // luu vi tri ki tu doan dung 
                    *(luu + k) = *(s + k);    //luu ky tu doan dung
                    sum++;
                    continue;
                }
                
                if (luuso[k] == k)
                {         
                    printf("%c", *(luu + k));
                    continue;
                }  
                
                printf("*");
            }
            printf("\n");

            ((person+i)->Score)[j] = sum; // nhan diem so sau moi lan tra loi
            //printf("nguoi thu %d diem thu %d co diem la = %d\n", i, j, ((person+i)->Score)[j]);
        }    
    }

    printf("\tHo va ten            L1  L2  L3  L4  L5(DOAN)  KETQUA\n");
    for (int i = 0; i < *M; i++)
    {    
        printf("\t%-21s%-4d%-4d%-4d%-4d%-10d%d\n", (person+i)->Name, ((person+i)->Score)[0], ((person+i)->Score)[1], ((person+i)->Score)[2], ((person+i)->Score)[3], ((person+i)->Score)[4], ((person+i)->Score)[0] + ((person+i)->Score)[1] + ((person+i)->Score)[2] + ((person+i)->Score)[3] + ((person+i)->Score)[4]);
    }
}
   
int main()
{
    int so,hito=0;
    int *M = &hito;
    Game person[10];    
    char s[61];
    
    do 
    {   
        clrscr();
        printf("1:Khoi dong tro choi.\n");
        printf("2:Choi doan ky tu.\n");
        printf("3:Tong hop ket qua.\n");
        printf("4:Thoat chuong trinh.\n");
        printf("5:Clear man hinh.\n");
        printf("Hay chon cac options tu 1-5: \n");
        scanf("%d", &so);
    
        switch(so)
        {
            case 1:
            dem++;
            khoidong(s, M, person);
            break;
            
            case 2:
            if (dem == 0)
            {
            printf("Ban chua nhap thong tin ve nguoi choi nao.\nMoi ban nhap so 1.\n");
            continue;
            }
            trochoi(s, M, person);
            system("pause");
            break;
            
            case 3: 
            if (dem == 0)
            {
            printf("Ban chua nhap thong tin ve nguoi choi nao.\nMoi ban nhap so 1.\n");
            continue;
            }
            printf("\tSTT  Ho va ten           KET QUA\n");
            for (int i = 0; i < *M; i++)
            {    
                printf("\t%-5d%-20s%d\n", i + 1, (person + i)->Name, ((person+i)->Score)[0] + ((person+i)->Score)[1] + ((person+i)->Score)[2] + ((person+i)->Score)[3] + ((person+i)->Score)[4]);
            }
            system("pause");
            break;

            case 4:
            break;

            case 5: // Clear man hinh
            clrscr();
            break;

        }
    }
    while (so != 4);//while (so==1||so==2||so==3||so==4); //neu chon option 1 thi se quay lai nhap tiep chon tiep cac options
    // CU Nhan vao nut 6 la thoat.

    return 0;
}
