5
    int valueRemoved;
    curr = head;

    while(curr->next->next != NULL){
        curr = curr->next;
    }
    valueRemoved = curr->next->value;
    curr->next = NULL;

    printf("\nRemoved %d\n", valueRemoved);
}

void removeSpecific(){
    int valueToRemove;
    curr = head;
    display();

    printf("Enter value to remove - ");
    scanf("%d", &valueToRemove);

    while (curr->next->value != valueToRemove){
        curr = curr->next;
    }

    valueToRemove = curr->next->value;

    curr->next = curr->next->next;
    printf("Node removed - %d\n", valueToRemove);
    display();
}