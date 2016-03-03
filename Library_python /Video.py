from Media import Media

class Video(Media):
   def __init__(self, call_no, title, subjects, description, 
                distibutor, notes, series, label):
      super().__init__(call_no, title, subjects)
      self.description = description
      self.distributor = distibutor
      self.notes = notes
      self.series = series
      self.label = label

   def display(self):
      super().display()
      print ( "Description: ", self.description, "Distributor: ", self.distributor, "Notes: ", self.notes,"Series: ", self.series,"Label: ", self.label)
   
   def compareByOther(self, search):
      if search in self.description or \
         search in self.distributor or \
         search in self.notes or \
         search in self.series or \
         search in self.label:
         return True
      else:
         return False

