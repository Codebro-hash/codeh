class BankAccount:

 def __init__(self):
    self.balance = 0

 def deposit(self, amount):
    self.balance += amount

 def withdraw(self, amount):
    if amount <= self.balance:
       self.balance -= amount

    else:
        print("Insufficient balance.")

 def get_balance(self):
    return self.balance

def main():
    account = BankAccount()

    while True:
        data= input("Enter the transaction you want to do: ")
        if data == 'Exit':
           break

        parts = data.split()

        transaction_type = parts[0]
        amount = int(parts[1])

        if transaction_type == 'D':
            account.deposit(amount)

        elif transaction_type == 'W':
            account.withdraw(amount)

        else:
             print("Invalid transaction type.")

        print("Current Balance:", account.get_balance())

main()