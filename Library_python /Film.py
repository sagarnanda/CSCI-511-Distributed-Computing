from Media import Media

class Film(Media):
   def __init__(self, call_no, title, subjects, director, notes, year):
      super().__init__(call_no, title, subjects)
      self.director = director
      self.year = year
      self.notes = notes

   def display(self):
      super().display()
      print ( "Director: ", self.director, "Notes: ", self.notes, "Year: ", self.year)
   
   def compareByOther(self, search):
      if search in self.director or \
         search in self.year or \
         search in self.notes:
         return True
      else:
         return False

