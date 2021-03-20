for j in range(10):
    emails = []
    a = int(input())
    for i in range(a):
        email = input()
        email = email.lower()

        if list(email).count("+") > 0:
            start = email.find("+")
            end = email.find("@")
            email = list(email)
            for x in range(end-start):
                email.pop(start)
            email = "".join(email)

        dots = (email.split("@")[0]).count(".")
        email = list(email)
        for x in range(dots):
            email.remove(".")
        email = "".join(email)
        emails.append(email)

    emails = set(emails)

    print(len(emails))