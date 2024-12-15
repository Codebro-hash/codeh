def delete_duplicates(l1):
    res = []
    for book in l1:
        if book not in res:
            res.append(book)
    return res

def sorting(l1):
    l1.sort(key=lambda x: x['cost'])  # Sort by cost in ascending order
    return l1

def count_above_500(l1):
    count = 0
    for book in l1:
        if book['cost'] > 500:
            count += 1
    return count

def copy_below_500(l1):
    res = []
    for book in l1:
        if book['cost'] < 500:
            res.append(book)
    return res

books = [
    {'name': 'Book A', 'author': 'Author 1', 'cost': 450},
    {'name': 'Book B', 'author': 'Author 2', 'cost': 600},
    {'name': 'Book C', 'author': 'Author 1', 'cost': 300},
    {'name': 'Book A', 'author': 'Author 1', 'cost': 450},  # Duplicate
    {'name': 'Book D', 'author': 'Author 3', 'cost': 700},
    {'name': 'Book E', 'author': 'Author 4', 'cost': 400},
    {'name': 'Book F', 'author': 'Author 5', 'cost': 100}
]

print("Books after removing duplicates:")
books_no_duplicates = delete_duplicates(books)
for book in books_no_duplicates:
    print(f"Book Name: {book['name']}, Author: {book['author']}, Cost: {book['cost']}")

print("\nBooks after sorting by cost:")
sorted_books = sorting(books)
for book in sorted_books:
    print(f"Book Name: {book['name']}, Author: {book['author']}, Cost: {book['cost']}")

print("\nNumber of books costing above 500:")
print(count_above_500(books))

print("\nBooks costing below 500:")
books_below_500 = copy_below_500(books)
for book in books_below_500:
    print(f"Book Name: {book['name']}, Author: {book['author']}, Cost: {book['cost']}")
