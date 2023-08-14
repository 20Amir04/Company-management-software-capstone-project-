    #include <iostream>
    #include <fstream>
    #include <string>
    #include <vector>

    using namespace std;
    /*
    У цьому коді використано принцип із ООП "інкапсуляція" у вигляді Getters та Setters
    для роботи з приватними полями класу Company, щоб забезпечити захист даних від невірного використання.
    getters та setters - типовий приклад інкапсуляції, вони захищают дані від зовнішнього доступу шляхом дозволу доступу до даних
    лише через визначені функції, як то getRank() чи setRank().
    */
    class Company
    {
    private:
        int rank;
        string companyName;
        string owner;
        string address;
        string phoneNumber;
        string material;
        string product;
    public:
        Company() {} // Constructor
        ~Company() {} // Desctructor

        // Getters - щоб отримати значення приватних полів класу Company

        int getRank() const {return rank; }
        string getCompanyName() const { return companyName; }
        string getOwner() const { return owner; }
        string getAddress() const { return address; }
        string getPhoneNumber() const { return phoneNumber; }
        string getMaterial() const { return material; }
        string getProduct() const { return product; }

        // Setters - щоб встановити дані до приватних полів класу Company

        void setRank(int r) { rank = r; }
        void setCompanyName(const string& n) { companyName = n; }
        void setOwner(const string& o) { owner = o; }
        void setAddress(const string& a) { address = a; }
        void setPhoneNumber(const string& p) { phoneNumber = p; }
        void setMaterial(const string& m) { material = m; }
        void setProduct(const string& p) { product = p; }
    };

    class CompanyManager // керування каталогом компаній
    {
    private:
        vector<Company> companies;
    public:
        void loadCompanies()
        {
            ifstream inputFile("Companies.txt");

            if (inputFile.is_open())
            {
                Company company;
                int rank;
                string companyName;
                string owner;
                string address;
                string phoneNumber;
                string material;
                string product;

                cout << endl << " Catalog of carpentry companies: " << endl;
                cout << endl;
                while (inputFile >> rank)
                {
                    inputFile.ignore();
                    getline(inputFile, companyName);
                    getline(inputFile, owner);
                    getline(inputFile, address);
                    getline(inputFile, phoneNumber);
                    getline(inputFile, material);
                    getline(inputFile, product);

                    if (!companyName.empty())
                    {
                        company.setRank(rank);
                        company.setCompanyName(companyName);
                        company.setOwner(owner);
                        company.setAddress(address);
                        company.setPhoneNumber(phoneNumber);
                        company.setMaterial(material);
                        company.setProduct(product);

                        companies.push_back(company);
                    }
                }
                inputFile.close();
            }
            else
            {
                cout << "Unable to open file Companies.txt" << endl;
            }
        }

        void saveCompanies()
        {
            ofstream outputFile("Companies.txt");

            if (outputFile.is_open())
            {
                for (const Company& company : companies)
                {
                     outputFile << company.getRank() << endl;
                outputFile << company.getCompanyName() << endl;
                outputFile << company.getOwner() << endl;
                outputFile << company.getAddress() << endl;
                outputFile << company.getPhoneNumber() << endl;
                outputFile << company.getMaterial() << endl;
                outputFile << company.getProduct() << endl;
                }
                outputFile.close();
            }
        }

        void addCompany()
        {
            Company company;
            int rank;
            string companyName;
            string owner;
            string address;
            string phoneNumber;
            string material;
            string product;

            string password;

            cout << "Input password: " << endl;
            cin >> password;

            if (password != "12348765")
            {
                cout << "Wrong password!" << endl;
            }
            else
            {
                cout << "Input company rank: " << endl;
                cin >> rank;
                cin.ignore();

                cout << "Input company name: " << endl;
                getline(cin, companyName);

                cout << "Input owner full name: " << endl;
                getline(cin, owner);

                cout << "Input company address: " << endl;
                getline(cin, address);

                cout << "Input company phone number: " << endl;
                getline(cin, phoneNumber);

                cout << "Input company materials: " << endl;
                getline(cin, material);

                cout << "Input company products: " << endl;
                getline(cin, product);

                company.setRank(rank);
                company.setCompanyName(companyName);
                company.setOwner(owner);
                company.setAddress(address);
                company.setPhoneNumber(phoneNumber);
                company.setMaterial(material);
                company.setProduct(product);

                cout << endl;
                cout << "Company was added successfully" << endl;
                cout << endl;

                companies.push_back(company);

                saveCompanies();
            }
        }

        void displayCompanies()
        {
            for (const Company& company : companies)
            {
                cout << "Top " << company.getRank() << ": " << "[" << company.getCompanyName() << "]" << endl << "  | " << company.getAddress() << " | " << endl
                    << "  | +1 " << company.getPhoneNumber() << " | " << endl << "  Owner: " << company.getOwner() << endl
                    << "  Materials: " << company.getMaterial() << endl << "  Productions: " << company.getProduct() << endl;
                cout << endl;
            }
        }

        void findCompanyByRank(int rank)
        {
            bool found = false;

            for (const Company& company : companies)
            {
                if (company.getRank() == rank)
                {
                    cout << "Company found: " << endl;
                    cout << endl;
                    cout << "Top " << company.getRank() << ": " << "[" << company.getCompanyName() << "]" << endl << "  | " << company.getAddress() << " | " << endl
                        << "  | +1 " << company.getPhoneNumber() << " | " << endl << "  Owner: " << company.getOwner() << endl
                        << "  Materials: " << company.getMaterial() << endl << "  Productions: " << company.getProduct() << endl;
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "No company found with rank [" << rank << "]" << endl;
            }
        }

        void findCompanyByName(const string& name)
        {
            bool found = false;

            for (const Company& company : companies)
            {
                if (company.getCompanyName() == name)
                {
                    cout << "Company found: " << endl;
                    cout << endl;
                    cout << "Top " << company.getRank() << ": " << "[" << company.getCompanyName() << "]" << endl << "  | " << company.getAddress() << " | " << endl
                        << "  | +1 " << company.getPhoneNumber() << " | " << endl << "  Owner: " << company.getOwner() << endl
                        << "  Materials: " << company.getMaterial() << endl << "  Productions: " << company.getProduct() << endl;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "No company found with name [" << name << "]" << endl;
            }
        }

        void deleteCompanyByRank(int rank)
        {

            for (auto it = companies.begin(); it != companies.end(); ++it) // begin - повертає ітератор на перший елемент вектору, ітератор як вказівник на елемент вектору
                // auto - дає змогу компілятору автоматично визначати тип даних (як var). end - вказує на кінець вектору
            {
                if (it->getRank() == rank)
                {
                    companies.erase(it); // видалення компоненту, на який вказує ітератор it
                    cout << "Company with rank " << rank << " has been deleted." << endl;
                    cout << endl;
                    return;
                }
            }
            cout << "Company with rank " << rank << " not found." << endl;
            cout << endl;

            saveCompanies();

        }
    };


    int main()
    {
        CompanyManager manager;

        manager.loadCompanies();
        manager.displayCompanies();
    

        int menu;
        string name;
        string password;

    start:

        cout << endl << "Choose an action: " << endl;
        cout << "1. Add Company info " << endl;
        cout << "2. Find company by rank " << endl;
        cout << "3. Find company by name " << endl;
        cout << "4. Delete company by rank " << endl;
        cout << "5. Exit " << endl;

        cin >> menu;
        if (cin.fail())
        {
            cout << "Menu is empty!";
            return 0;
        }

        switch (menu)
        {
        case 1:
            manager.addCompany();
            manager.saveCompanies();
            cout << endl << " Catalog of carpentry companies: " << endl;
            cout << endl;
            manager.displayCompanies();
            goto start;
            break;
         case 2:
            int rank;
            cout << "Enter company rank to search: ";
            cout << endl;
            cin >> rank;
            manager.findCompanyByRank(rank);
            goto start;
            break;
            case 3:
                cout << "Enter company name to search: ";
                cout << endl;
                cin.ignore(); 
                getline(cin, name);
                manager.findCompanyByName(name);
                goto start;
                break;
            case 4:
                cout << "Input password: " << endl;
                cin >> password;

                if (password != "12348765")
                {
                    cout << "Wrong password!" << endl;
                }
                else
                {
                    rank;
                    cout << "Enter company rank to delete: " << endl;
                    cout << endl;
                    cin >> rank;
                    manager.deleteCompanyByRank(rank);
                    manager.saveCompanies();
                    cout << endl << " Catalog of carpentry companies: " << endl;
                    cout << endl;
                    manager.displayCompanies();
                }
                goto start;
                break;
            case 5:
            return 0;
            break;
        default:
            cout << "You need to choose one of the suggested actions." << endl;
            goto start;
        }
        return 0;
    }



