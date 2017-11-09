
class ATM(object):
  
    MAX_AMOUNT = 2000
    BANK_CHARGE_FOR_EACH_WITHDRAWAL = 0.5

    def __init__(self, initial_amount):
        self.initial_amount = initial_amount
        # if self.initial_amount > ATM.MAX_AMOUNT or self.initial_amount < 0:
        #     raise Exception


    def withdraw(self, amount_to_withdraw):
        # if amount_to_withdraw > ATM.MAX_AMOUNT or amount_to_withdraw < 0:
        #     raise Exception
        if amount_to_withdraw % 5 != 0 or (amount_to_withdraw + ATM.BANK_CHARGE_FOR_EACH_WITHDRAWAL) >= self.initial_amount:
            current_bank_balance =  self.initial_amount
        else:
            current_bank_balance = self.initial_amount - amount_to_withdraw - ATM.BANK_CHARGE_FOR_EACH_WITHDRAWAL

        return "{:.2f}".format(current_bank_balance)


amount_to_withdraw,initial_amount = input().split()
amount_to_withdraw = int(amount_to_withdraw)
initial_amount = float(initial_amount)

atm = ATM(initial_amount)
result = atm.withdraw(amount_to_withdraw)
print(result)


# inputs = list(map(int, input().split()))
# atm = ATM(inputs[1])
# result = atm.withdraw(inputs[0])

# print(result)
