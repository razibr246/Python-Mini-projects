#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct DailyReport {
    string month;
    int week;
    int day;

    int fajr, zuhr, asr, maghrib, isha;
    int quranCount;
    int hadithCount;
    int islamicBookPages;
    int goodDeeds;
    double charity;
    int exercise;
    int selfReview;
};

vector<DailyReport> reports;

void addReport() {
    DailyReport r;

    cout << "\nEnter Month (e.g., January): ";
    cin >> r.month;

    cout << "Enter Week Number (1-5): ";
    cin >> r.week;

    cout << "Enter Day (1-31): ";
    cin >> r.day;

    cout << "Fajr prayed (1=Yes, 0=No): ";
    cin >> r.fajr;
    cout << "Zuhr prayed (1=Yes, 0=No): ";
    cin >> r.zuhr;
    cout << "Asr prayed (1=Yes, 0=No): ";
    cin >> r.asr;
    cout << "Maghrib prayed (1=Yes, 0=No): ";
    cin >> r.maghrib;
    cout << "Isha prayed (1=Yes, 0=No): ";
    cin >> r.isha;

    cout << "Quran pages read: ";
    cin >> r.quranCount;

    cout << "Hadith read count: ";
    cin >> r.hadithCount;

    cout << "Islamic book pages: ";
    cin >> r.islamicBookPages;

    cout << "Number of good deeds: ";
    cin >> r.goodDeeds;

    cout << "Charity amount given: ";
    cin >> r.charity;

    cout << "Exercise done (minutes): ";
    cin >> r.exercise;

    cout << "Self review done (1=Yes, 0=No): ";
    cin >> r.selfReview;

    reports.push_back(r);

    cout << "\nReport Added Successfully!\n";
}

void viewReports() {
    if (reports.empty()) {
        cout << "\nNo reports available.\n";
        return;
    }

    for (const auto &r : reports) {
        cout << "\n=============================\n";
        cout << "Month: " << r.month << endl;
        cout << "Week: " << r.week << endl;
        cout << "Day: " << r.day << endl;

        cout << "Namaz: "
             << "Fajr(" << r.fajr << ") "
             << "Zuhr(" << r.zuhr << ") "
             << "Asr(" << r.asr << ") "
             << "Maghrib(" << r.maghrib << ") "
             << "Isha(" << r.isha << ")\n";

        cout << "Quran Pages: " << r.quranCount << endl;
        cout << "Hadith Count: " << r.hadithCount << endl;
        cout << "Islamic Book Pages: " << r.islamicBookPages << endl;
        cout << "Good Deeds: " << r.goodDeeds << endl;
        cout << "Charity: " << r.charity << endl;
        cout << "Exercise (minutes): " << r.exercise << endl;
        cout << "Self Review: " << r.selfReview << endl;
    }
}

void saveToFile() {
    ofstream file("reports.txt", ios::app);  // append mode

    if (!file) {
        cout << "Error opening file!\n";
        return;
    }

    for (const auto &r : reports) {
        file << r.month << " "
             << r.week << " "
             << r.day << " "
             << r.fajr << " "
             << r.zuhr << " "
             << r.asr << " "
             << r.maghrib << " "
             << r.isha << " "
             << r.quranCount << " "
             << r.hadithCount << " "
             << r.islamicBookPages << " "
             << r.goodDeeds << " "
             << r.charity << " "
             << r.exercise << " "
             << r.selfReview << endl;
    }

    file.close();
    cout << "\nData Saved Successfully!\n";
}

void loadFromFile() {
    ifstream file("reports.txt");

    if (!file) {
        cout << "No saved file found.\n";
        return;
    }

    DailyReport r;
    reports.clear();

    while (file >> r.month
                >> r.week
                >> r.day
                >> r.fajr
                >> r.zuhr
                >> r.asr
                >> r.maghrib
                >> r.isha
                >> r.quranCount
                >> r.hadithCount
                >> r.islamicBookPages
                >> r.goodDeeds
                >> r.charity
                >> r.exercise
                >> r.selfReview) {

        reports.push_back(r);
    }

    file.close();
    cout << "\nData Loaded Successfully!\n";
}

int main() {
    int choice;

    do {
        cout << "\n===== Daily Personal Report System =====\n";
        cout << "1. Add Report\n";
        cout << "2. View Reports\n";
        cout << "3. Save to File\n";
        cout << "4. Load from File\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addReport(); break;
            case 2: viewReports(); break;
            case 3: saveToFile(); break;
            case 4: loadFromFile(); break;
            case 5: cout << "Exiting Program...\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
