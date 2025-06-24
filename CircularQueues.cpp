/**
 * @mainpage Dokumentation Circular Queue
 * 
 * @section Introduction
 * project ini merupakan project struktur data
 * menggunakan struktur data Queues dengan pendekatan circular array
 * 
 * @section Operation 
 * project ini memiliki beberapa operasi santara lain:
 * 1. Insert
 * 2. Delete
 * 3. Display
 * 
 * @section Cara Penggunaan
 * berikut beberapa menu yang bisa digunakan:
 * 1. en queue
 * 2. de queue
 * 3. display
 * 4. exit
 * 
 * @author profil
 * Nama : Jundi Al-Faruq Reksowardoyo
 * NIM : 20240140100
 * Kelas : B
 * 
 * @brief
 * @version
 * @date
 * 
 * @copyright Copyright (c) jundi.alfaruq.ft24@umy.ac.id 2025 
 */





#include <iostream>
using namespace std;
/**
 * @class Queue
 * @brief class ini untuk oprasi lengkap queue
 */


class Queues
{
private :
    
    int FRONT; //variable privat front untuk menyimpan posisi depan antrian
    int REAR; // variable private rear untuk menyimpan posisi belakang antrian
    int max = 5; // variable private max untuk menyimpan ukuran maximum antrian
    int queue_array[5]; // variable private queue_array untuk menyimpan elemen antrian

public :
    /**
     * @brief Construct a new Queue object
     * set default  queues null
     * with front = -1 and rear = -1
     */
    Queues()
    {
        FRONT = -1;
        REAR = -1;
    }
    /**
     * @brief method untuk masukan data dalam antrian
     * data dimasukan dalam variable queue_array
     */

    void insert()
    {
        int num; // variable num untuk menyimpan nilai
        cout << "Enter a number : ";
        cin >> num;
        cout << endl;

        //1. Cek apakah antrian penuh
        if ((FRONT == 0 && REAR == max -1) || (FRONT == REAR + 1))
        {
            cout << "\nQueue overflow\n";   // 2.b
            return;                         // 1.b
        }
        
        // 2. Cek apakah antrian kosong
        if (FRONT == -1)
        {
            FRONT = 0; // 2.a
            REAR = 0; // 2.B
        }
        else
        {
            // jika REAR berada diposisi terakhir array, kembali ke awal array
            if (REAR == max - 1)
                REAR = 0;
            else
                REAR = REAR + 1;
        }
        queue_array[REAR] = num;
    }

    /**
     * @brief method untuk menghapus data dalam antrian
     * data dihapuskan dari dalam variable queue_array
     */

    void remove()
    {
        //cek apakah antrian kosong
        if (FRONT == -1)
        {
            cout << "Queue underflow\n";
            return;
        }
        cout << "\nThe Elemen delete from the queue is : " << queue_array [FRONT] << "\n";

        // Cek jika antrian hanya memiliki satu elemen
        if (FRONT == REAR)
        {
            FRONT = -1;
            REAR= -1;
        }
        else
        {
            // jIKA ELEMEN YANG DIHAPUS bearada di posisi terakhir array, kembali ke awal array
            if (FRONT == max -1)
                FRONT = 0;
            else
                FRONT = FRONT + 1;


        }
        
    }
    /**
     * @brief method untuk menampilkan data dalam antrian
     * data ditampilkan yang berada dalam variable  queue_array
     */

    void display()
    {
        int FORNT_position = FRONT; ///< variable front_position untuk menandakan posisi elemen pertama pada variable front 
        int REAR_position = REAR; ///< variable rear_position untuk menandakan posisi elemen terakhir pada variable rear

        // cek apakah antrian kosong
        if (FRONT == -1)
        {
            cout << "Queue is empty\n";
            return;
        }

        cout << "\nElemen in the queue are....\n";

        // Jika FRONT_position <= REAR_position, iterasi dari FRONT hingga Rear
        if (FORNT_position <= REAR_position)
        {
            while (FORNT_position <= REAR_position)
            {
                cout << queue_array[FORNT_position] << "    ";
                FORNT_position++;
            }
            cout << endl;
        }
        else
        {
            // jika FRONT_position > REAR_position, iterasi dari FRONT higga akhir array
            while (FORNT_position <= max - 1)
            {
                cout << queue_array[FORNT_position] << "     ";
                FORNT_position++;
            }
            FORNT_position = 0;

            // Iterasi dari awal array hingga REAR
            while (FORNT_position <= REAR_position)
            {
                cout << queue_array[FORNT_position] << "    ";
                FORNT_position++;
            }
            cout << endl;
        }

    }

};
/**
 * @brief method utama menggunakan member yang ada pada clas Queues
 * 
 * @return int
 */

int main()
{
    Queues q; ///< objek untuk menggunakan member yang ada pada class Queues
    char ch; ///< variable ch untuk menyimpan pilihan pada menu yang diberikan

    while (true)
    {
        try
        {
            cout << "Menu" << endl;
            cout << "1. Implement Insert operation" << endl;
            cout << "2. Implement delete operation" << endl;
            cout << "3. Display values" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter you choice (1-4) : ";
            cin>> ch;
            cout << endl;

            switch (ch)
            {
            case '1' :
            {
                q.insert();
                break;
            }
            case '2' :
            {
                q.remove();
                break;
            }
            case '3' :
            {
                q.display();
                break;
            }
            case '4' :
            {
                return 0;
            }
            default :
            {
                cout << "Invalid option!!" << endl;
                break;
            }
            }
        }
        catch (exception &e)
        {
            cout << "Check for the values entered." << endl;
        }
    }
    
    return 0;
}