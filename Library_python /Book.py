from Media import Media

class Book(Media):
   def __init__(self, call_no, title, subjects, author, description, 
                publisher, city, year, series, notes):
      super().__init__(call_no, title, subjects)
      self.author = author
      self.description = description
      self.publisher = publisher
      self.city = city
      self.year = year
      self.series = series
      self.notes = notes

   def display(self):
      super().display()
      print ( "Author: ", self.author, "Description: ", self.description, "Publisher: ", self.publisher, "City: ", self.city, "Year: ", self.year, "Series: ", self.series, "Notes: ", self.notes)
   
   def compareByOther(self, search):
      if search in self.author or \
         search in self.description or \
         search in self.publisher or \
         search in self.city or \
         search in self.year or \
         search in self.series or \
         search in self.notes:
         return True
      else:
         return False

