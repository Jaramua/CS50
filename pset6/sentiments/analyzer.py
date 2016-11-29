import nltk

class Analyzer():
    """Implements sentiment analysis."""

    def __init__(self, positives="positive-words.txt", negatives="negative-words.txt"):
        """Initialize Analyzer."""
        self.posdata = set()
        self.negdata = set()
        file = open(positives, "r")
        for line in file:
            if line.find(';'):
                self.posdata.add(line.rstrip("\n"))
        file.close()
        file = open(negatives, "r")
        for line in file:
            if line.find(';'):
                self.negdata.add(line.rstrip("\n"))
        file.close()

    def analyze(self, text):
        """Analyze text for sentiment, returning its score."""
        tokenizer = nltk.tokenize.TweetTokenizer() 
        tokens = tokenizer.tokenize(text.lower())
        score = 0
        for i in self.posdata:
            for j in tokens:
                if j == i:
                    score += 1
        for i in self.negdata:
            for j in tokens:
                if j == i:
                    score -= 1            
                    
        return score
