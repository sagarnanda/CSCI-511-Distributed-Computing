from SearchEngine import SearchEngine

def displayMenu():
   print("**********************************************Choose Option for Search Category**********************************************")
   print("Press 1 for Search by Call Number.")
   print("Press 2 for Search by Subject. ")
   print("Press 3 for Search by Title.")
   print("Press 4 for Search by Other.")
   print("Press 5 to Exit.")
   option = input("Choose option:")
   return option

def main():
   se = SearchEngine()
   option_str = displayMenu()
   option = int(option_str)
   while(option !=5):
      results = list()
      if option == 1:
         callNumber = input("Enter Call Number: ")
         results = se.search_by_call_no(callNumber)
         se.display(results)
      elif option == 2:
         subject = input("Enter Subject: ")
         results = se.search_by_subjects(subject)
         se.display(results)
      elif option == 3:
         title = input("Enter Title: ")
         results = se.search_by_title(title)
         se.display(results)
      elif option == 4:
         other = input("Enter Other : ")
         results = se.search_by_other(other)
         se.display(results)
      else:
         print('\n')   
         print("Enter Correct option:")
      print('\n')   
      print("Total No. of Matching Result: ", len(results))
      print('\n')   
      option_str = displayMenu()
      option = int(option_str)


if __name__ == "__main__":
   main()
