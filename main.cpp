#include <iostream>
#include "LinkedList.h"
#include "DynamicArray.h"
#include "DoublyLinkedList.h"
#include <chrono>
#include <numeric>
#include <vector>
#include <memory>
#include <fstream>

using namespace std;
using namespace std::chrono;

#include <vector>
#include <fstream>
#include <string>

using namespace std;
// funkcja służy do zapisania wygenerowanej bazy do pliku
string save_data(vector<int> data, string path)
{
   ofstream file(path);
   if (!file.is_open())
   {
      return "Failed to open file.";
   }
   for (size_t i = 0; i < 130000; ++i)
   {
      file << data[i] << '\n';
   }

   file.close();
   return "Data saved successfully.";
}
// funckja służy do odczytania bazy z pliku
string load_data(vector<int> &data, int size, string path)
{
   ifstream file(path);
   if (!file.is_open())
   {
      return "Failed to open file.";
   }
   data.resize(size);
   for (int i = 0; i < size; i++)
   {
      file >> data[i];
   }
   file.close();
   return "Data loaded successfully.";
}
// funckja służy do wygenerowania losowej bazy wartości od 0 do 49 o podanym rozmiarze
vector<int> set_common_data(int size)
{
   vector<int> commonData;
   srand(time(0));
   for (int i = 0; i < size; i++)
   {
      commonData.push_back(rand() % 50);
   }
   return commonData;
}
// funckja zwraca wektor zawieracy 100 tablic dynamicznych zawierających takie same wypełnienie
vector<unique_ptr<DynamicArray>> set_array(vector<int> commonData)
{
   vector<unique_ptr<DynamicArray>> arrays;
   for (int i = 0; i < 100; i++)
   {
      arrays.push_back(make_unique<DynamicArray>());
   }

   for (auto &arr : arrays)
   {
      for (int value : commonData)
      {
         arr->add_first(value);
      }
   }
   return arrays;
}
// funckja zwraca wektor zawieracy 100 list jednokierunkowych zawierających takie same wypełnienie
vector<unique_ptr<LinkedList>> set_linked_list(vector<int> commonData)
{
   vector<unique_ptr<LinkedList>> linked_lists;
   for (int i = 0; i < 100; i++)
   {
      linked_lists.push_back(make_unique<LinkedList>());
   }

   for (auto &lis : linked_lists)
   {
      for (int value : commonData)
      {
         lis->add_first(value);
      }
   }
   return linked_lists;
}
// funckja zwraca wektor zawieracy 100 list dwukierunkowych zawierających takie same wypełnienie
vector<unique_ptr<DoublyLinkedList>> set_doubly_linked_list(vector<int> commonData)
{
   vector<unique_ptr<DoublyLinkedList>> doubly_linked_lists;
   for (int i = 0; i < 100; i++)
   {
      doubly_linked_lists.push_back(make_unique<DoublyLinkedList>());
   }

   for (auto &dob : doubly_linked_lists)
   {
      for (int value : commonData)
      {
         dob->add_first(value);
      }
   }
   return doubly_linked_lists;
}

int main()
{
   // vector<int> commonData = set_common_data(40000);

   /*
   int data_choice = 0;
   int size = 0;
   int operation = 0;
   cout << "This program tests various operations on multiple data structures. Please choose your desired data structure, then enter the desired size, and finally choose the operation to perform." << endl;
   cout << "1. Dynamic Array"<< endl;
   cout << "2. Linked List"<< endl;
   cout << "3. Doubly Linked List"<< endl;
   cin >> data_choice;
   cout << "Enter yout desired size: ";
   cin >> size;
   */

   // vector<int> commonData = set_common_data(130000);
   vector<int> commonData;
   int k = 5000;

   do
   {

      load_data(commonData, k, "data.txt"); // wczytanie bazy o określonym rozmiarze

      long long fin_arr_time = 0; // inicjalizacja zmiennym do których będziemy zapisywać czas
      long long test_time_arr = 0;
      vector<unique_ptr<DynamicArray>> arrays = set_array(commonData); // utworzenie wektora z 100 kopiami struktury o określonyn rozmiarze
      for (int i = 0; i < 100; i++)
      {
         auto start = high_resolution_clock::now();                         // start licznika czasu
         arrays[i]->add_first(1);                                           // Dodajemy element na początek
         auto stop = high_resolution_clock::now();                          // koniec licznika czasu
         test_time_arr += duration_cast<nanoseconds>(stop - start).count(); // obliczenie czasu
      }
      fin_arr_time += test_time_arr; // Dodajemy czas tej iteracji do ogólnego czasu
      // cout << "DYNAMIC ARRAY ADD FIRST: " << endl;
      cout << fin_arr_time << endl;

      long long fin_lis_time = 0; // inicjalizacja zmiennym do których będziemy zapisywać czas
      long long test_time_lis = 0;
      vector<unique_ptr<LinkedList>> lists = set_linked_list(commonData); // utworzenie wektora z 100 kopiami struktury o określonyn rozmiarze
      for (int i = 0; i < 10; i++)
      {
         auto start1 = high_resolution_clock::now();
         lists[i]->add_first(1); // Dodajemy element na początek
         auto stop1 = high_resolution_clock::now();
         test_time_lis += duration_cast<nanoseconds>(stop1 - start1).count();
      }
      fin_lis_time += test_time_lis; // Dodajemy czas tej iteracji do ogólnego czasu
      // cout << "LINKED LIST ADD FIRST: " << endl
      cout << fin_lis_time << endl;

      long long fin_dob_time = 0; // inicjalizacja zmiennym do których będziemy zapisywać czas
      long long test_time_dob = 0;
      vector<unique_ptr<DoublyLinkedList>> doubly = set_doubly_linked_list(commonData); // utworzenie wektora z 100 kopiami struktury o określonyn rozmiarze
      for (int i = 0; i < 100; i++)
      {
         auto start2 = high_resolution_clock::now();
         doubly[i]->add_first(1); // Dodajemy element na początek
         auto stop2 = high_resolution_clock::now();
         test_time_dob += duration_cast<nanoseconds>(stop2 - start2).count();
      }
      fin_dob_time += test_time_dob; // Dodajemy czas tej iteracji do ogólnego czasu
      // cout << "DOUBLY LINKED ADD FIRST: " << endl;
      cout << fin_dob_time << endl;

      k += 5000;
   } while (k <= 110000);

   do
   {
      load_data(commonData, k, "data.txt"); // wczytanie bazy o określonym rozmiarze

      long long fin_arr_time = 0; // inicjalizacja zmiennym do których będziemy zapisywać czas
      long long test_time_arr = 0;
      vector<unique_ptr<DynamicArray>> arrays = set_array(commonData); // utworzenie wektora z 100 kopiami struktury o określonyn rozmiarze
      for (int i = 0; i < 100; i++)
      {
         auto start = high_resolution_clock::now();
         arrays[i]->add_back(1); // Dodajemy element na koniec
         auto stop = high_resolution_clock::now();
         test_time_arr += duration_cast<nanoseconds>(stop - start).count();
      }
      fin_arr_time += test_time_arr;
      cout << fin_arr_time << endl;
      long long fin_lis_time = 0; // inicjalizacja zmiennym do których będziemy zapisywać czas
      long long test_time_lis = 0;
      vector<unique_ptr<LinkedList>> lists = set_linked_list(commonData); // utworzenie wektora z 100 kopiami struktury o określonyn rozmiarze
      for (int i = 0; i < 100; i++)
      {
         auto start1 = high_resolution_clock::now();
         lists[i]->add_back(1); // Dodajemy element na koniec
         auto stop1 = high_resolution_clock::now();
         test_time_lis += duration_cast<nanoseconds>(stop1 - start1).count();
      }
      fin_lis_time += test_time_lis;
      cout << fin_lis_time << endl;

      long long fin_dob_time = 0; // inicjalizacja zmiennym do których będziemy zapisywać czas
      long long test_time_dob = 0;
      vector<unique_ptr<DoublyLinkedList>> doubly = set_doubly_linked_list(commonData); // utworzenie wektora z 100 kopiami struktury o określonyn rozmiarze
      for (int i = 0; i < 100; i++)
      {
         auto start2 = high_resolution_clock::now();
         doubly[i]->add_back(1);
         auto stop2 = high_resolution_clock::now();
         test_time_dob += duration_cast<nanoseconds>(stop2 - start2).count();
      }
      fin_dob_time += test_time_dob;
      cout << fin_dob_time << endl;

      k += 5000;
   } while (k <= 110000);

   do
   {
      load_data(commonData, k, "data.txt"); // wczytanie bazy o określonym rozmiarze

      long long test_time_arr2 = 0; // inicjalizacja zmiennym do których będziemy zapisywać czas
      long long fin_arr_time2 = 0;
      vector<unique_ptr<DynamicArray>> arrays = set_array(commonData); // utworzenie wektora z 100 kopiami struktury o określonyn rozmiarze
      for (int i = 0; i < 100; i++)
      {
         auto start = high_resolution_clock::now();
         arrays[i]->add_at(1, k / 2); // Dodajemy element na początek
         auto stop = high_resolution_clock::now();
         test_time_arr2 += duration_cast<nanoseconds>(stop - start).count();
      }
      fin_arr_time2 += test_time_arr2; // Dodajemy czas tej iteracji do ogólnego czasu
      // cout << "DYNAMIC ARRAY ADD AT: " << endl;
      cout << fin_arr_time2 << endl;

      long long fin_lis_time2 = 0; // inicjalizacja zmiennym do których będziemy zapisywać czas
      long long test_time_lis2 = 0;
      vector<unique_ptr<LinkedList>> lists = set_linked_list(commonData); // utworzenie wektora z 100 kopiami struktury o określonyn rozmiarze
      for (int i = 0; i < 100; i++)
      {
         auto start1 = high_resolution_clock::now();
         lists[i]->add_at(1, k / 2); // Dodajemy element na początek
         auto stop1 = high_resolution_clock::now();
         test_time_lis2 += duration_cast<nanoseconds>(stop1 - start1).count();
      }
      fin_lis_time2 += test_time_lis2; // Dodajemy czas tej iteracji do ogólnego czasu
      // cout << "LINKED LIST ADD AT: " << endl;
      cout << fin_lis_time2 << endl;
      long long fin_dob_time2 = 0; // inicjalizacja zmiennym do których będziemy zapisywać czas
      long long test_time_dob2 = 0;
      vector<unique_ptr<DoublyLinkedList>> doubly = set_doubly_linked_list(commonData); // utworzenie wektora z 100 kopiami struktury o określonyn rozmiarze
      for (int i = 0; i < 100; i++)
      {
         auto start2 = high_resolution_clock::now();
         doubly[i]->add_at(1, k / 2); // Dodajemy element na początek
         auto stop2 = high_resolution_clock::now();
         test_time_dob2 += duration_cast<nanoseconds>(stop2 - start2).count();
      }
      fin_dob_time2 += test_time_dob2; // Dodajemy czas tej iteracji do ogólnego czasu
      // cout << "DOUBLY LINKED ADD AT: " << endl;
      cout << fin_dob_time2 << endl;

      k += 5000;
   } while (k <= 110000);

   do
   {
      load_data(commonData, k, "data.txt"); // wczytanie bazy o określonym rozmiarze

      long long fin_arr_time3 = 0; // inicjalizacja zmiennym do których będziemy zapisywać czas
      long long test_time_arr3 = 0;
      vector<unique_ptr<DynamicArray>> arrays = set_array(commonData); // utworzenie wektora z 100 kopiami struktury o określonyn rozmiarze
      for (int i = 0; i < 100; i++)
      {
         auto start = high_resolution_clock::now();
         arrays[i]->pop_first(); // Dodajemy element na początek
         auto stop = high_resolution_clock::now();
         test_time_arr3 += duration_cast<nanoseconds>(stop - start).count();
      }
      fin_arr_time3 += test_time_arr3; // Dodajemy czas tej iteracji do ogólnego czasu
      // cout << "DYNAMIC ARRAY POP FIRST: " << endl;
      cout << fin_arr_time3 << endl;

      long long fin_lis_time3 = 0; // inicjalizacja zmiennym do których będziemy zapisywać czas
      long long test_time_lis3 = 0;
      vector<unique_ptr<LinkedList>> lists = set_linked_list(commonData); // utworzenie wektora z 100 kopiami struktury o określonyn rozmiarze
      for (int i = 0; i < 100; i++)
      {
         auto start1 = high_resolution_clock::now();
         lists[i]->pop_first(); // Dodajemy element na początek
         auto stop1 = high_resolution_clock::now();
         test_time_lis3 += duration_cast<nanoseconds>(stop1 - start1).count();
      }
      fin_lis_time3 += test_time_lis3; // Dodajemy czas tej iteracji do ogólnego czasu
      // cout << "LINKED LIST POP FIRST: " << endl;
      cout << fin_lis_time3 << endl;

      long long fin_dob_time3 = 0; // inicjalizacja zmiennym do których będziemy zapisywać czas
      long long test_time_dob3 = 0;
      vector<unique_ptr<DoublyLinkedList>> doubly = set_doubly_linked_list(commonData); // utworzenie wektora z 100 kopiami struktury o określonyn rozmiarze
      for (int i = 0; i < 100; i++)
      {
         auto start2 = high_resolution_clock::now();
         doubly[i]->pop_first(); // Dodajemy element na początek
         auto stop2 = high_resolution_clock::now();
         test_time_dob3 += duration_cast<nanoseconds>(stop2 - start2).count();
      }
      fin_dob_time3 += test_time_dob3; // Dodajemy czas tej iteracji do ogólnego czasu
      // cout << "DOUBLY LINKED POP FIRST: " << endl;
      cout << fin_dob_time3 << endl;
      k += 5000;
   } while (k <= 110000);

   do
   {
      load_data(commonData, k, "data.txt"); // wczytanie bazy o określonym rozmiarze

      long long fin_arr_timeb4 = 0; // inicjalizacja zmiennym do których będziemy zapisywać czas
      long long test_time_arrb4 = 0;
      vector<unique_ptr<DynamicArray>> arrays = set_array(commonData); // utworzenie wektora z 100 kopiami struktury o określonyn rozmiarze
      for (int i = 0; i < 100; i++)
      {
         auto start = high_resolution_clock::now();
         arrays[i]->pop_back(); // Dodajemy element na początek
         auto stop = high_resolution_clock::now();
         test_time_arrb4 += duration_cast<nanoseconds>(stop - start).count();
      }
      fin_arr_timeb4 += test_time_arrb4; // Dodajemy czas tej iteracji do ogólnego czasu
      // cout << "DYNAMIC ARRAY POP BACK: " << endl;
      cout << fin_arr_timeb4 << endl;

      long long test_time_lisb4 = 0; // inicjalizacja zmiennym do których będziemy zapisywać czas
      long long fin_lis_timeb4 = 0;
      vector<unique_ptr<LinkedList>> lists = set_linked_list(commonData); // utworzenie wektora z 100 kopiami struktury o określonyn rozmiarze
      for (int i = 0; i < 100; i++)
      {
         auto start1 = high_resolution_clock::now();
         lists[i]->pop_back(); // Dodajemy element na początek
         auto stop1 = high_resolution_clock::now();
         test_time_lisb4 += duration_cast<nanoseconds>(stop1 - start1).count();
      }
      fin_lis_timeb4 += test_time_lisb4; // Dodajemy czas tej iteracji do ogólnego czasu
      // cout << "LINKED LIST POP BACK: " << endl;
      cout << fin_lis_timeb4 << endl;

      long long fin_dob_timeb4 = 0; // inicjalizacja zmiennym do których będziemy zapisywać czas
      long long test_time_dobb4 = 0;
      vector<unique_ptr<DoublyLinkedList>> doubly = set_doubly_linked_list(commonData); // utworzenie wektora z 100 kopiami struktury o określonyn rozmiarze
      for (int i = 0; i < 100; i++)
      {
         auto start2 = high_resolution_clock::now();
         doubly[i]->pop_back(); // Dodajemy element na początek
         auto stop2 = high_resolution_clock::now();
         test_time_dobb4 += duration_cast<nanoseconds>(stop2 - start2).count();
      }
      fin_dob_timeb4 += test_time_dobb4; // Dodajemy czas tej iteracji do ogólnego czasu
      // cout << "DOUBLY LINKED POP BACK: " << endl;
      cout << fin_dob_timeb4 << endl;

      k += 5000;
   } while (k <= 110000);

   do
   {
      load_data(commonData, k, "data.txt"); // wczytanie bazy o określonym rozmiarze

      long long fin_arr_time25 = 0; // inicjalizacja zmiennym do których będziemy zapisywać czas
      long long test_time_arr25 = 0;
      vector<unique_ptr<DynamicArray>> arrays = set_array(commonData); // utworzenie wektora z 100 kopiami struktury o określonyn rozmiarze
      for (int i = 0; i < 100; i++)
      {
         auto start = high_resolution_clock::now();
         arrays[i]->pop_at(k / 2); // Dodajemy element na początek
         auto stop = high_resolution_clock::now();
         test_time_arr25 += duration_cast<nanoseconds>(stop - start).count();
      }
      fin_arr_time25 += test_time_arr25; // Dodajemy czas tej iteracji do ogólnego czasu
      // cout << "DYNAMIC ARRAY POP AT: " << endl;
      cout << fin_arr_time25 << endl;
      long long fin_lis_time25 = 0; // inicjalizacja zmiennym do których będziemy zapisywać czas
      long long test_time_lis25 = 0;
      vector<unique_ptr<LinkedList>> lists = set_linked_list(commonData); // utworzenie wektora z 100 kopiami struktury o określonyn rozmiarze
      for (int i = 0; i < 100; i++)
      {
         auto start1 = high_resolution_clock::now();
         lists[i]->pop_at(k / 2); // Dodajemy element na początek
         auto stop1 = high_resolution_clock::now();
         test_time_lis25 += duration_cast<nanoseconds>(stop1 - start1).count();
      }
      fin_lis_time25 += test_time_lis25; // Dodajemy czas tej iteracji do ogólnego czasu
      // cout << "LINKED LIST POP AT: " << endl;
      cout << fin_lis_time25 << endl;

      long long fin_dob_time25 = 0; // inicjalizacja zmiennym do których będziemy zapisywać czas
      long long test_time_dob25 = 0;
      vector<unique_ptr<DoublyLinkedList>> doubly = set_doubly_linked_list(commonData); // utworzenie wektora z 100 kopiami struktury o określonyn rozmiarze
      for (int i = 0; i < 100; i++)
      {
         auto start2 = high_resolution_clock::now();
         doubly[i]->pop_at(k / 2); // Dodajemy element na początek
         auto stop2 = high_resolution_clock::now();
         test_time_dob25 += duration_cast<nanoseconds>(stop2 - start2).count();
      }
      fin_dob_time25 += test_time_dob25; // Dodajemy czas tej iteracji do ogólnego czasu
      // cout << "DOUBLY LINKED POP AT: " << endl;
      cout << fin_dob_time25 << endl;

      k += 5000;
   } while (k <= 110000);

   do
   {
      long long fin_dob_time26 = 0; // inicjalizacja zmiennym do których będziemy zapisywać czas
      long long fin_lis_time26 = 0;
      long long fin_arr_time26 = 0;
      load_data(commonData, k, "data.txt"); // wczytanie bazy o określonym rozmiarze

      long long test_time_arr26 = 0;
      vector<unique_ptr<DynamicArray>> arrays = set_array(commonData); // utworzenie wektora z 100 kopiami struktury o określonyn rozmiarze
      for (int i = 0; i < 100; i++)
      {
         auto start = high_resolution_clock::now();
         arrays[i]->search(37);
         auto stop = high_resolution_clock::now();
         test_time_arr26 += duration_cast<nanoseconds>(stop - start).count();
      }
      fin_arr_time26 += test_time_arr26;
      // cout << "DYNAMIC ARRAY SEARCH: " << endl;
      cout << test_time_arr26 << endl;

      long long test_time_lis26 = 0;
      vector<unique_ptr<LinkedList>> lists = set_linked_list(commonData); // utworzenie wektora z 100 kopiami struktury o określonyn rozmiarze
      for (int i = 0; i < 100; i++)
      {
         auto start = high_resolution_clock::now();
         lists[i]->search(37);
         auto stop = high_resolution_clock::now();
         test_time_lis26 += duration_cast<nanoseconds>(stop - start).count();
      }
      fin_lis_time26 += test_time_lis26;
      // cout << "LINKED LIST SEARCH: " << endl;
      cout << test_time_lis26 << endl;

      long long test_time_dob26 = 0;
      vector<unique_ptr<DoublyLinkedList>> doubly = set_doubly_linked_list(commonData); // utworzenie wektora z 100 kopiami struktury o określonyn rozmiarze
      for (int i = 0; i < 100; i++)
      {
         auto start = high_resolution_clock::now();
         doubly[i]->search(37);
         auto stop = high_resolution_clock::now();
         test_time_dob26 += duration_cast<nanoseconds>(stop - start).count();
      }
      fin_dob_time26 += test_time_dob26;
      // cout << "DOUBLY LINKED LIST SEARCH: " << endl;
      cout << test_time_dob26 << endl;

      k += 5000;
   } while (k <= 110000);
}
