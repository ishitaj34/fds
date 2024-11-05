import json

def load_recipes():
    try:
        with open('recipes.json', 'r') as file:
            recipes = json.load(file)
    except (FileNotFoundError, json.JSONDecodeError):
        recipes = {}
        
    return recipes


def view_recipes():
    if not recipes:
        print("No recipes found.")
    else:
        print("\nRecipes available:")
        for recipe_name in recipes:
            print(recipe_name)
                
        recipe_choice = input("\nEnter the name of the recipe you want to view: ")
        if recipe_choice.lower() in recipes:
            display_recipe(recipe_choice, recipes[recipe_choice])
        else:
            print("Recipe not found.")


def add_recipe():
    recipe_name = input("\nEnter the name of the recipe: ")
    ingredients = input("\nEnter the ingredients (comma-separated): ").split(',')
    
    instructions = []
    print("\nEnter the cooking instructions one by one. Type 'done' on a new line when finished).")
    while True:
        step = input("Instruction: ")
        if step.lower() == 'done':
            break
        instructions.append(step)
        
    category = input("\nEnter the category of the recipe: ")

    recipes[recipe_name] = {
        'ingredients': ingredients,
        'instructions': instructions,
        'category': category
    }

    print(f"\nRecipe '{recipe_name}' added successfully!")
    
    
def edit_recipe():
    recipe_name = input("\nEnter the name of the recipe you want to edit: ")

    if recipe_name in recipes:
        print(f"\nEditing Recipe: {recipe_name}")
        print("1. Edit Ingredients")
        print("2. Edit Instructions")
        print("3. Edit Category")
        print("4. Back to Main Menu")

        choice = int(input("\nEnter your choice: "))

        if choice == 1:
            edit_ingredients(recipe_name)
        elif choice == 2:
            edit_instructions(recipe_name)
        elif choice == 3:
            edit_category(recipe_name)
        elif choice == 4:
            return
        else:
            print("Invalid choice. Please try again.")

    else:
        print(f"Recipe '{recipe_name}' not found.")
        
        
def edit_ingredients(recipe_name):
    new_ingredients = input("\nEnter the new ingredients (comma-separated): ").split(',')
    recipes[recipe_name]['ingredients'] = new_ingredients


def edit_instructions(recipe_name):
    # To retrieve the existing instructions
    existing_instructions = recipes[recipe_name]['instructions']

    print("\nCurrent Instructions:")
    for step in existing_instructions:
        print(f"- {step}")

    print("\nEnter the new instructions. Type 'done' on a new line when finished.")

    new_instructions = []
    while True:
        step = input("Instruction: ")
        if step.lower() == 'done':
            break
        else:
            new_instructions.append(step)

    # To update the recipe with the new instructions
    recipes[recipe_name]['instructions'] = new_instructions
    print(f"\nInstructions for '{recipe_name}' updated successfully.")


def edit_category(recipe_name):
    new_category = input("\nEnter the new category of the recipe: ")
    recipes[recipe_name]['category'] = new_category
        
        
def save_recipes(recipes):
    with open('recipes.json', 'w') as file:
        json.dump(recipes, file, indent=2)
   
        
def display_recipe(recipe_name, recipes):
    print(f"\n\nRecipe: {recipe_name}")
    
    print("\nIngredients:")
    for ingredient in recipes['ingredients']:
        print(f"-{ingredient}")
        
    print("\nCooking Instructions:")
    for step in recipes['instructions']:
        print(f"- {step}")
        
    print("\nCategory:", recipes['category'])


def sort_recipes_by_name():
    sorted_recipes = dict(sorted(recipes.items()))
    
    print("\nSorted recipes:")
    for recipe_name in sorted_recipes:
        print(f"{recipe_name}")
        
    ans = input("\nDo you want to view any recipe?(enter yes/no)")
    if(ans.lower()=="yes"):
        recipe_choice = input("\nEnter the name of the recipe you want to view: ")
        if recipe_choice.lower() in recipes:
            display_recipe(recipe_choice, recipes[recipe_choice])
        else:
            print("Recipe not found.")
        

def filter_recipes_by_category(recipes):
    unique_categories = []
    recommended_recipes = {}

    # To compile list of the categories available
    for recipe in recipes.values():
        category = recipe.get('category', 'Uncategorized')
        if category not in unique_categories:
            unique_categories.append(category)

    print("\nAvailable Categories:")
    for category in unique_categories:
        print(category)
    
    # To compile list of recipes under chosen category
    category1 = input("\nEnter the category of the recipe you would like to make: ")

    for name, recipe in recipes.items():
        category = recipe.get('category', '').lower()
        if category == category1.lower():
            recommended_recipes[name] = recipe

    if recommended_recipes:
        print("\nRecommended Recipes:")
        for recipe_name, recipe_details in recommended_recipes.items():
            display_recipe(recipe_name, recipe_details)
    else:
        print(f"\nNo recipes found in the '{category1}' category.")

# Main function
recipes = load_recipes()

print("\n\n\t*** MENU FOR RECIPE MANAGEMENT SYSTEM ***\t\n")
print("1. View Recipes")
print("2. Add Recipe")
print("3. Edit Recipe")
print("4. Sort Recipes")
print("5. Recommended Recipes")
print("6. Save and Quit")
print("\n\t\t\t*** END ***\t\t\t\n\n")

a = 1;
while a == 1:
    choice = int(input("\nEnter your choice: "))

    if choice == 1:
        view_recipes()

    elif choice == 2:
        add_recipe()
        
    elif choice == 3:
        edit_recipe()

    elif choice == 4:
        sort_recipes_by_name()

    elif choice == 5:
        filter_recipes_by_category(recipes)

    elif choice == 6:
        save_recipes(recipes)
        print("Recipes saved. Exiting...")
        break

    else:
        print("Invalid choice.")
        
    print("\nDo you want to perform more operations? (enter yes/no)")
    ans = input()
    if(ans.lower()=="yes"):
        a = 1
    else: 
        a = 0
        print("\nThank you for using our software :)") 
