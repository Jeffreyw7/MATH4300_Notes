class String {
public:
    String();
    explicit String(const char* s);
    ~String();

    String(const String& other);
    String& operator=(const String& other);

    String(String&& other) noexcept;            // move constructor
    String& operator=(String&& other) noexcept; // move assignment

    size_t size()  const;
    bool   empty() const;
    char   at(size_t i) const;
    const char* c_str() const;

private:
    size_t len_;
    char*  data_;
};