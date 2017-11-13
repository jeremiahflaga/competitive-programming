import unittest
from TEST import getEntriesBefore42


class AtmTests(unittest.TestCase):

    def __init__(self, *args, **kwargs):
        unittest.TestCase.__init__(self, *args, **kwargs) 

    def test_should_return_empty_list_if_original_list_is_empty(self):
        result = getEntriesBefore42([])        
        self.assertListEqual([], result)

    def test_should_return_empty_list_if_42_is_the_only_item_in_the_list(self):
        result = getEntriesBefore42([42])        
        self.assertListEqual([], result)

    def test_should_return_correct_list(self):
        result = getEntriesBefore42([1, 2, 88, 42, 56])        
        self.assertListEqual([1, 2, 88,], result)

    def test_should_return_all_items_in_original_list_if_42_is_not_in_list(self):
        result = getEntriesBefore42([1, 2, 3])        
        self.assertListEqual([1, 2, 3], result)


if __name__ == '__main__':
    unittest.main()
