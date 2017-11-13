import unittest
from atm import ATM


class AtmTests(unittest.TestCase):

    def __init__(self, *args, **kwargs):
        unittest.TestCase.__init__(self, *args, **kwargs) 

    def test_should_return_correct_balance_if_amount_to_withdraw_is_5(self):
        atm = ATM(7)
        result = atm.withdraw(5)
        self.assertEqual("1.50", result)

    def test_should_return_correct_balance_if_amount_to_withdraw_is_10(self):
        atm = ATM(17)
        result = atm.withdraw(10)
        self.assertEqual("6.50", result)

    def test_should_return_current_balance_if_amount_to_withdraw_is_not_a_multiple_of_5(self):
        atm = ATM(7)
        result = atm.withdraw(4)
        self.assertEqual("7.00", result)

    def test_should_return_current_balance_if_amount_to_withdraw_is_more_than_current_balance(self):
        atm = ATM(7)
        result = atm.withdraw(9)
        self.assertEqual("7.00", result)

    def test_should_return_current_balance_if_amount_to_withdraw_is_equal_to_current_balance(self):
        atm = ATM(5)
        result = atm.withdraw(5)
        self.assertEqual("5.00", result)


# class AtmTests_CashToWithdrawInputBoundaryTests(unittest.TestCase):

#     def __init__(self, *args, **kwargs):
#         unittest.TestCase.__init__(self, *args, **kwargs)        
#         anonymous_initial_amount = 1500
#         self.atm = ATM(anonymous_initial_amount)

#     def test_should_throw_error_if_cash_to_withdraw_is_greater_than_2000(self):
#         with self.assertRaises(Exception):
#             self.atm.withdraw(2001)

#     def test_should_throw_error_if_cash_to_withdraw_is_less_than_zero(self):
#         with self.assertRaises(Exception):
#             self.atm.withdraw(-1)

#     def test_should_not_throw_error_if_cash_to_withdraw_is_less_than_2000(self):
#         self.atm.withdraw(1999)
#         # no exception expected

#     def test_should_not_throw_error_if_cash_to_withdraw_is_equal_to_2000(self):
#         self.atm.withdraw(2000)
#         # no exception expected


# class AtmTests_InitialAccountInputBoundaryTests(unittest.TestCase):

#     def test_should_throw_error_if_initial_account_is_greater_than_2000(self):
#         with self.assertRaises(Exception):
#             ATM(2001)
            
#     def test_should_throw_error_if_initial_account_is_less_than_zero(self):
#         with self.assertRaises(Exception):
#             ATM(-1)

#     def test_should_not_throw_error_if_initial_account_is_less_than_2000(self):
#         ATM(1999)
#         # no exception expected

#     def test_should_not_throw_error_if_initial_account_is_equal_to_2000(self):
#         ATM(2000)
#         # no exception expected


if __name__ == '__main__':
    unittest.main()
