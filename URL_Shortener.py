
class URLShortener:
    def _init_(self):
        self.long_to_short = {}
        self.short_to_long = {}
        self.base_url = "https://ShortURL.ro/"
        self.chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
        self.counter = 0

    def generate_short_url(self):
        short_url = self.base_url + self.encode_base62(self.counter).zfill(4)
        self.counter += 1
        return short_url

    def encode_base62(self, num):
        if num == 0:
            return "0"
        result = ""
        while num:
            num, rem = divmod(num, 62)
            result = self.chars[rem] + result
        return result

    def process_query(self, query):
        query_type, param = query.split(' ', 1)
        if query_type == '1':
            long_url = param.strip()
            if long_url not in self.long_to_short:
                short_url = self.generate_short_url()
                self.long_to_short[long_url] = short_url
                self.short_to_long[short_url] = long_url
            else:
                short_url = self.long_to_short[long_url]
            return short_url
        elif query_type == '2':
            short_url = param.strip()
            long_url = self.short_to_long.get(short_url, "nu exista")
            return long_url


if __name__ == "_main_":
    url_shortener = URLShortener()
    N = int(input())
    for _ in range(N):
        query = input()
        print(url_shortener.process_query(query))