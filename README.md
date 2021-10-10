# ATM MACHINE PROJECT
The above project is the completed version of the ATM Machine Code compiled in C++ Language as part of the 
assignment from  ZOHO Corporation on 11/10/2021 
###  By Vaishnav K

## Project Setup
1. Clone the Project/Download the zip file uploaded 
2. Install Coderunner extension in Visual studio Code suitable for running C++ Programs
3. Make sure that the text files provided/downloaded are saved under the same folder 
4. Run the code to update the values in the respective files as per your required operations 

### Administrator password = 1234

### Note : 
 - Please Do not enter commas (,) in-between the amounts
 - Ensure that the conditions are satisfied under a certain operation 
 - Ie: if an error message is displayed , the updating process wont take place 

## Some of the errors-criteria to avoid are
 - Insufficient money under the required denomination
 - Insufficient money in the customer account
 - Incorrect password or pin number
 - Exceeding the Amount per transaction – withdrawal/transfer
 - Limit for withdrawal =[Rs 100 – Rs 10,000]
 - Limit for transfer    = [Rs 1000- Rs 10,000]




## Working
I have successfully implemented the following functions/Operations on this project:

#### i). Addition of Denomination:
  This option lets the user log in as an administrator using the administrator password (1234) and it lets the administrator add money of the provided denominations (Rs 2000,     500, 100)
  This option also subsequently displays the total denominations table which is stored as "balance.txt" 
  This operation is suggested when the balance of any certain denomination is below the sufficient limit


#### ii). Display Customer table:
  This option allows the administrator to view all the customer details which includes
  
  - account no
  - account name
  - pin number
  - balance
  
  The Customer account details are stored in the file "accounts.txt" inside the folder
  Note: Administrators are only granted view access to the customer table


#### iii.). Handle ATM Process:
  This option is exclusively for the customers of the bank 
  This option requires the user to type in their account number and password
  After successful verification , the user is provided with 5 options

**a. Check balance :**
This option displays the user balance obtained from the file "accounts.txt";

**b. Withdraw money :**
This option allows the user to withdraw money (limit 10000 per transaction) after re-entering the pin
Once the transaction is complete , the user's account balance is updated in the file "accounts.txt"
The respective denomination amounts are also updated in the file "balance.txt" 
If the sufficient money is not available in the ATM Machine , the transaction does not take place and the user is informed of the reason.
The mini statement file which is saved under "<customer_id>_transactions.txt" is also updated.
 
**c. Transfer money :**
Using this option , the user can transfer a certain amount (limit 10000 per transaction) to any account of his/her choice
The user is required to enter the account ID of the user to be transferred to , and if there are required balance in the account, the transaction takes place
The respective balances are updated in both of the accounts in the file "accounts.txt"
The mini statement file of both the accounts are updated in the given circumstances.

**d. Check ATM balance :**
This allows the administrator upon entering the administrator password(1234) to view the balance of the ATM under the provided denominations
The file "balance.txt" is displayed

**e. View Mini statement :** 
This allows the user to view the mini statement of the previous 10 transactions 
Displays the file "<customer_id>_transactions.txt"

#### iv). The customer is provided with an option to re-enter the required operations upon typing "y"
The customer can exit the ATM Machine by entering any other letter.


Finally ,the customer is greeted with a GoodBye message prompting them to have a great day.
