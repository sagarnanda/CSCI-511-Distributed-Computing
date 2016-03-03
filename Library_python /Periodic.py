from Media import Media

class Periodic(Media):
   def __init__(self, call_no, title, subjects, author, description, 
                publisher, publisherHistory, series, notes,
                relatedTitles, otherTitles, govDocNumber):
      super().__init__(call_no, title, subjects)
      self.author = author
      self.description = description
      self.publisher = publisher
      self.publisherHistory = publisherHistory
      self.series = series
      self.notes = notes
      self.relatedTitles = relatedTitles
      self.otherTitles = otherTitles
      self.govDocNumber = govDocNumber

   def display(self):
      super().display()
      print ( "Author: ", self.author, "Description: ", self.description, "Publisher:", self.publisher, "PublisherHistory: ", self.publisherHistory, "Series: ", self.series, "Notes: ", self.notes,"Related Titles: ", self.relatedTitles, "Other Titles: ", self.otherTitles, "Gov Doc Number: ", self.govDocNumber)
   
   def compareByOther(self, search):
      if search in self.author or \
         search in self.description or \
         search in self.publisher or \
         search in self.publisherHistory or \
         search in self.series or \
         search in self.notes or \
         search in self.relatedTitles or \
         search in self.otherTitles or \
         search in self.govDocNumber:
         return True
      else:
         return False

