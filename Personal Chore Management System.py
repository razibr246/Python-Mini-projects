ChoreListJj = ["Clean The Litter", "Make Food", "Organize Clothes", "Clean The Room", "Feed Cats", "Clean Water"]

Username2 = "Jj"

Name = input("Enter your name: ")

if Name == Username2:
    print("Hello Jj, your chores are: ", ChoreListJj)

    if len(ChoreListJj) == 0:
        input("You have completed all your chores, press Any Button to exit")

    while len(ChoreListJj) > 0:
        ChoresDone = input("Which chores have you done? ")

        ChoresDone = ChoresDone.title()
        ChoresDone = ChoresDone.strip()

        if ChoresDone in ChoreListJj:
            ChoreListJj.remove(ChoresDone)

            if len(ChoreListJj) > 0:
                print("Good Job Jj, your remaining chores are: ", ChoreListJj)

            if len(ChoreListJj) == 0:
                completed = input("You have completed all your chores, press Enter Button to exit")
                break
