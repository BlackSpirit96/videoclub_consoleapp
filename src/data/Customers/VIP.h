#ifndef VIP_H_
#define VIP_H_

#include "../Customer.h"

class VIP: public Customer
{
public:
	VIP(string id, string firstName,
			string lastName, string dateOfBirth,
			string genderText, string adress,
			string phoneNumber, string credidCardNumber,
			string issuingNetwork, int cvv);
    string getCredidCardNumber();
    int getCvv();
    string getIssuingNetwork();
    void setCredidCardNumber(string credidCardNumber);
    void setCvv(int cvv);
    void setIssuingNetwork(string issuingNetwork);
	bool isVIP() { return true;}
private:
	string credidCardNumber;
	string issuingNetwork;
	int cvv;
};

#endif /* VIP_H_ */
