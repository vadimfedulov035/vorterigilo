with open("nations.txt", "r") as f:
    for line in f.readlines():
        if "ano" in line or "gento" in line or "/uj/" in line:
            root = line.split("/")[0]
            if root[0].islower():
                print(root)
