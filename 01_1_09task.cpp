#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "os_file.h"
#pragma warning (disable:4996)

struct Vertex_ {
    bool isDirectory;
    char* name;
    int size;
    Vertex_* parent;
    Vertex_* child;
    Vertex_* leftbrother;
    Vertex_* rightbrother;
};

typedef Vertex_ Vertex;

Vertex *root = NULL, *currentDirectory = NULL;
int diskSize;
bool fileManagerIsCreated = false;

int MyCreate(int disk_size)
{
    if ((disk_size > 0) && (!fileManagerIsCreated))
    {
        //Creating root directory
        root = (Vertex*)calloc(1, sizeof(Vertex));
        root->name = (char*)calloc(2, sizeof(char));
        strcpy(root->name, "/");
        root->isDirectory = 1;
        root->size = 0;
        root->child = NULL;
        root->parent = NULL;
        root->leftbrother = NULL;
        root->rightbrother = NULL;
        diskSize = disk_size;
        fileManagerIsCreated = true;
        currentDirectory = root;
    }
    else
        return 0;

    return 1;
}

// Case of absolute path: /sardor/univer/programming/task1 -> programming
// Case of relative path: sardor/univer/programming/task1 -> programming
Vertex* FindPenUltimateDirectoryInPath (const char* path)
{
    Vertex* v = NULL;

    //Absolute path case
    if (path[0] == '/')
    {
        char** name = NULL;
        int *slashindex = NULL, slashcount = 0, index = 0, counter;
        bool flag;
        Vertex* child = NULL;

        for (int i = 0; i < strlen(path); ++i)
        {
            if (path[i] == '/')
            {
                ++slashcount;
            }
        }

        slashindex = (int*)calloc(slashcount, sizeof(int));
        name = (char**)calloc(slashcount - 1, sizeof(char*));
        slashcount = 0;

        for (int i = 0; i < strlen(path); ++i)
        {
            if (path[i] == '/')
            {
                slashindex[slashcount] = i;
                ++slashcount;
            }
        }

        for (int i = 0; i < slashindex[slashcount - 1]; ++i)
        {
            if (slashindex[index] == i)
            {
                ++index;
                name[index - 1] = (char*)calloc(slashindex[index] - slashindex[index - 1], sizeof(char));
                counter = 0;
            }
            else
            {
                name[index - 1][counter] = path[i];
                ++counter;
                if (slashindex[index] == i + 1)
                {
                    name[index - 1][counter] = '\0';
                }
            }
        }

        child = root;
        v = child;

        for (int i = 0; i < index; ++i)
        {
            flag = false;

            v = (child)->child;

            if (!v)
            {
                if (strcmp(name[i], ".") == 0)
                {
                    v = child;
                    flag = true;
                }
                else if (strcmp(name[i], "..") == 0)
                {
                    if (child->parent != NULL)
                    {
                        child = child->parent;
                        v = child;
                        flag = true;
                    }
                }
            }

            while (v && !flag)
            {
                if (strcmp(name[i], v->name) == 0 && v->isDirectory)
                {
                    child = v;
                    flag = true;
                }
                else if (strcmp(name[i], ".") == 0)
                {
                    flag = true;
                }
                else if (strcmp(name[i], "..") == 0)
                {
                    if (child->parent != NULL)
                    {
                        child = child->parent;
                        flag = true;
                    }
                }
                else
                {
                    v = v->rightbrother;
                }
            }
            if (!flag)
            {
                v = NULL;
            }
        }
        child = NULL;
        for (int i = 0; i < index; ++i)
        {
            free(name[i]);
            name[i] = NULL;
        }
        free(name);
        name = NULL;
    }
    else //Relative path case
    {
        char** name = NULL;
        int* slashindex = NULL, slashcount = 1, index = 0, counter;
        bool flag;
        Vertex* child = NULL;

        for (int i = 0; i < strlen(path); ++i)
        {
            if (path[i] == '/')
            {
                ++slashcount;
            }
        }

        slashindex = (int*)calloc(slashcount, sizeof(int));
        name = (char**)calloc(slashcount - 1, sizeof(char*));
        slashindex[0] = -1;
        slashcount = 1;

        for (int i = 0; i < strlen(path); ++i)
        {
            if (path[i] == '/')
            {
                slashindex[slashcount] = i;
                ++slashcount;
            }
        }

        for (int i = -1; i < slashindex[slashcount - 1]; ++i)
        {
            if (slashindex[index] == i)
            {
                ++index;
                name[index - 1] = (char*)calloc(slashindex[index] - slashindex[index - 1], sizeof(char));
                counter = 0;
            }
            else
            {
                name[index - 1][counter] = path[i];
                ++counter;
                if (slashindex[index] == i + 1)
                {
                    name[index - 1][counter] = '\0';
                }
            }
        }

        child = currentDirectory;
        v = child;

        for (int i = 0; i < index; ++i)
        {
            flag = false;

            v = child->child;

            if (!v)
            {
                if (strcmp(name[i], ".") == 0)
                {
                    v = child;
                    flag = true;
                }
                else if (strcmp(name[i], "..") == 0)
                {
                    if (child->parent != NULL)
                    {
                        child = child->parent;
                        v = child;
                        flag = true;
                    }
                }
            }

            while (v && !flag)
            {
                if (strcmp(name[i], v->name) == 0 && v->isDirectory)
                {
                    child = v;
                    flag = true;
                }
                else if (strcmp(name[i], ".") == 0)
                {
                    v = child;
                    flag = true;
                }
                else if (strcmp(name[i], "..") == 0)
                {
                    if (child->parent != NULL)
                    {
                        v = child->parent;
                        child = child->parent;
                        flag = true;
                    }
                }
                else
                {
                    v = v->rightbrother;
                }
            }
            
            if (!flag)
            {
                v = NULL;
            }
        }
        child = NULL;
        for (int i = 0; i < index; ++i)
        {
            free(name[i]);
            name[i] = NULL;
        }
        free(name); 
        name = NULL;
    }

    return v;
}

Vertex* FindUltimateDirectoryInPath(const char* path)
{
    Vertex* v = NULL;

    //Absolute path case
    if (path[0] == '/')
    {
        char** name = NULL;
        int* slashindex = NULL, slashcount = 1, index = 0, counter;
        bool flag;
        Vertex* child = NULL;

        for (int i = 0; i < strlen(path); ++i)
        {
            if (path[i] == '/')
            {
                ++slashcount;
            }
        }
        slashindex = (int*)calloc(slashcount, sizeof(int));
        name = (char**)calloc(slashcount - 1, sizeof(char*));
        slashindex[slashcount - 1] = strlen(path);
        slashcount = 0;

        for (int i = 0; i < strlen(path); ++i)
        {
            if (path[i] == '/')
            {
                slashindex[slashcount] = i;
                ++slashcount;
            }
        }
        ++slashcount;

        for (int i = 0; i < slashindex[slashcount - 1]; ++i)
        {
            if (slashindex[index] == i)
            {
                ++index;
                name[index - 1] = (char*)calloc(slashindex[index] - slashindex[index - 1], sizeof(char));
                counter = 0;
            }
            else
            {
                name[index - 1][counter] = path[i];
                ++counter;
                if (slashindex[index] == i + 1)
                {
                    name[index - 1][counter] = '\0';
                }
            }
        }

        child = root;
        v = child;

        for (int i = 0; i < index; ++i)
        {
            flag = false;

            v = (child)->child;

            if (!v)
            {
                if (strcmp(name[i], ".") == 0)
                {
                    v = child;
                    flag = true;
                }
                else if (strcmp(name[i], "..") == 0)
                {
                    if (child->parent != NULL)
                    {
                        child = child->parent;
                        v = child;
                        flag = true;
                    }
                }
            }

            while (v && !flag)
            {
                if (strcmp(name[i], v->name) == 0 && v->isDirectory && i != index - 1)
                {
                    child = v;
                    flag = true;
                    
                }
                else if (strcmp(name[i], v->name) == 0 && i == index - 1)
                {
                    flag = true;
                }
                else if (strcmp(name[i], ".") == 0)
                {
                    v = child;
                    flag = true;
                }
                else if (strcmp(name[i], "..") == 0)
                {
                    if (child->parent != NULL)
                    {
                        v = child->parent;
                        child = child->parent;
                        flag = true;
                    }
                }
                else
                {
                    v = v->rightbrother;
                }
            }
            
            if (!flag)
            {
                v = NULL;
            }
        }
        child = NULL;
        for (int i = 0; i < index; ++i)
        {
            free(name[i]);
            name[i] = NULL;
        }
        free(name);
        name = NULL;
    }
    else //Relative path case
    {
        char** name = NULL;
        int* slashindex = NULL, slashcount = 2, index = 0, counter;
        bool flag;
        Vertex* child = NULL;

        for (int i = 0; i < strlen(path); ++i)
        {
            if (path[i] == '/')
            {
                ++slashcount;
            }
        }
        slashindex = (int*)calloc(slashcount, sizeof(int));
        name = (char**)calloc(slashcount - 1, sizeof(char*));
        slashindex[0] = -1;
        slashindex[slashcount - 1] = strlen(path);
        slashcount = 1;

        for (int i = 0; i < strlen(path); ++i)
        {
            if (path[i] == '/')
            {
                slashindex[slashcount] = i;
                ++slashcount;
            }
        }
        ++slashcount;

        for (int i = -1; i < slashindex[slashcount - 1]; ++i)
        {
            if (slashindex[index] == i)
            {
                ++index;
                name[index - 1] = (char*)calloc(slashindex[index] - slashindex[index - 1], sizeof(char));
                counter = 0;
            }
            else
            {
                name[index - 1][counter] = path[i];
                ++counter;
                if (slashindex[index] == i + 1)
                {
                    name[index - 1][counter] = '\0';
                }
            }
        }

        child = currentDirectory;
        v = child;

        for (int i = 0; i < index; ++i)
        {
            flag = false;

            v = child->child;
            
            if (!v)
            {
                if (strcmp(name[i], ".") == 0)
                {
                    v = child;
                    flag = true;
                }
                else if (strcmp(name[i], "..") == 0)
                {
                    if (child->parent != NULL)
                    {
                        child = child->parent;
                        v = child;
                        flag = true;
                    }
                }
            }

            while (v && !flag)
            {
                if (strcmp(name[i], v->name) == 0 && v->isDirectory && i != index - 1)
                {
                    child = v;
                    flag = true;
                    
                }
                else if (strcmp(name[i], v->name) == 0 && i == index - 1)
                {
                    flag = true;
                }
                else if (strcmp(name[i], ".") == 0)
                {
                    v = child;
                    flag = true;
                }
                else if (strcmp(name[i], "..") == 0)
                {
                    if (child->parent != NULL)
                    {
                        child = child->parent;
                        v = child;
                        flag = true;
                    }
                }
                else
                {
                    v = v->rightbrother;
                }
            }
           
            if (!flag)
            {
                v = NULL;
            }
        }
        child = NULL;
        for (int i = 0; i < index; ++i)
        {
            free(name[i]);
            name[i] = NULL;
        }
    }

    return v;
}

 //Case of absolute path: /sardor/univer/programming/task1 -> if its possible there would be created directory 'task1'
 //Case of relative path: sardor/univer/programming/task1 -> if its possible there would be created directory 'task1'
int MyCreateDirectory(const char* path)
{
    int error = 1, lastSlashIndex = -1;
    Vertex *penultimate = NULL, *ultimate = NULL;

    if (fileManagerIsCreated)
    {
        penultimate = FindPenUltimateDirectoryInPath(path);

        for (int i = 0; i < strlen(path); ++i)
        {
            if (path[i] == '/')
            {
                lastSlashIndex = i;
            }
        }

        if (penultimate != NULL)
        {
            char* name = NULL;

            name = (char*)calloc(strlen(path) - lastSlashIndex, sizeof(char));

            for (int k = lastSlashIndex + 1; k < strlen(path); ++k)
            {
                name[k - lastSlashIndex - 1] = path[k];
            }

            name[strlen(path) - lastSlashIndex - 1] = '\0';

            if (strcmp(name, ".") == 0)
                error = 0;
            if (strcmp(name, "..") == 0)
                error = 0;
            if (strlen(name) > 32)
                error = 0;

            ultimate = penultimate->child;

            if (ultimate && error == 1)
            {
                while (1)
                {
                    if (strcmp(name, ultimate->name) == 0)
                    {
                        error = 0;
                        break;
                    }

                    if (ultimate->rightbrother)
                    {
                        ultimate = ultimate->rightbrother;
                    }
                    else
                    {
                        break;
                    }
                }
                if (error == 1)
                {
                    ultimate->rightbrother = (Vertex*)calloc(1, sizeof(Vertex));
                    ultimate->rightbrother->child = NULL;
                    ultimate->rightbrother->isDirectory = true;
                    ultimate->rightbrother->leftbrother = ultimate;
                    ultimate->rightbrother->name = (char*)calloc(strlen(name) + 1, sizeof(char));
                    strcpy(ultimate->rightbrother->name, name);
                    ultimate->rightbrother->parent = ultimate->parent;
                    ultimate->rightbrother->rightbrother = NULL;
                    ultimate->rightbrother->size = 0;
                }
            }
            else if (error == 1)
            {
                penultimate->child = (Vertex*)calloc(1, sizeof(Vertex));
                penultimate->child->child = NULL;
                penultimate->child->isDirectory = true;
                penultimate->child->leftbrother = NULL;
                penultimate->child->name = (char*)calloc(strlen(name) + 1, sizeof(char));
                strcpy(penultimate->child->name, name);
                penultimate->child->parent = penultimate;
                penultimate->child->rightbrother = NULL;
                penultimate->child->size = 0;
            }
        }
        else
            error = 0;
    }
    else
        error = 0;

    return error;
}

// Case of absolute path: /sardor/univer/programming/task1.txt -> if its possible there would be created directory 'task1.txt'
// Case of relative path: sardor/univer/programming/task1.jpg -> if its possible there would be created directory 'task1.jpg'
int MyCreateFile(const char* path, int fileSize)
{
    int error = 1, lastSlashIndex = -1;
    Vertex* penultimate = NULL, * ultimate = NULL;

    if (fileManagerIsCreated)
    {
        if (fileSize <= diskSize)
        {
            penultimate = FindPenUltimateDirectoryInPath(path);

            for (int i = 0; i < strlen(path); ++i)
            {
                if (path[i] == '/')
                {
                    lastSlashIndex = i;
                }
            }

            if (penultimate != NULL)
            {
                char* name = NULL;

                name = (char*)calloc(strlen(path) - lastSlashIndex, sizeof(char));

                for (int k = lastSlashIndex + 1; k < strlen(path); ++k)
                {
                    name[k - lastSlashIndex - 1] = path[k];
                }

                name[strlen(path) - lastSlashIndex - 1] = '\0';


                if (strcmp(name, ".") == 0)
                    error = 0;
                if (strcmp(name, "..") == 0)
                    error = 0;
                if (strlen(name) > 32)
                    error = 0;

                ultimate = penultimate->child;

                if (ultimate && error == 1)
                {
                    while (1)
                    {
                        if (strcmp(name, ultimate->name) == 0)
                        {
                            error = 0;
                            break;
                        }

                        if (ultimate->rightbrother)
                        {
                            ultimate = ultimate->rightbrother;
                        }
                        else
                        {
                            break;
                        }
                    }
                    if (error == 1)
                    {
                        ultimate->rightbrother = (Vertex*)calloc(1, sizeof(Vertex));
                        ultimate->rightbrother->child = NULL;
                        ultimate->rightbrother->isDirectory = false;
                        ultimate->rightbrother->leftbrother = ultimate;
                        ultimate->rightbrother->name = (char*)calloc(strlen(name) + 1, sizeof(char));
                        strcpy(ultimate->rightbrother->name, name);
                        ultimate->rightbrother->parent = ultimate->parent;
                        ultimate->rightbrother->rightbrother = NULL;
                        ultimate->rightbrother->size = fileSize;
                        diskSize -= fileSize;
                    }

                }
                else if (error == 1)
                {
                    penultimate->child = (Vertex*)calloc(1, sizeof(Vertex));
                    penultimate->child->child = NULL;
                    penultimate->child->isDirectory = false;
                    penultimate->child->leftbrother = NULL;
                    penultimate->child->name = (char*)calloc(strlen(name) + 1, sizeof(char));
                    strcpy(penultimate->child->name, name);
                    penultimate->child->parent = penultimate;
                    penultimate->child->rightbrother = NULL;
                    penultimate->child->size = fileSize;
                    diskSize -= fileSize;
                }
            }
            else
                error = 0;
        }
        else
            error = 0;
    }
    else
        error = 0;

    return error;
}

int MyFreeSpace()
{
    return diskSize;
}

// destination = absolute path to directory which might be accessed by the global pointer 'currentDirectory'
// /d1/d11/d112 -> 211d/11d/1d/->reverse string
void MyGetCurrentDirectory(char* destination)
{
    Vertex* current = currentDirectory;
    int length = 0;

    while (current->parent != NULL)
    {
        for (int i = 0; i < strlen(current->name); ++i)
        {
            destination[length] = current->name[strlen(current->name) - i - 1];
            ++length;
        }
        destination[length] = '/';
        ++length;
        current = current->parent;
    }

    for (int i = 0; i < length / 2; ++i)
    {
        char tmp = destination[i];
        destination[i] = destination[length - i - 1];
        destination[length - i - 1] = tmp;
    }
    destination[length] = '\0';
}

// Case of absolute path : / sardor / univer / programming / task1-> task1 <-- is current directory
// Case of relative path: sardor/univer/programming/task1 -> task1 <-- is current directory
int MyChangeDirectory(const char* path)
{  
    Vertex* last = FindUltimateDirectoryInPath(path);
    if (last)
    {
        currentDirectory = last;
    }
    else
        return 0;

    return 1;
}

int MyRemove(const char* path, int recursive)
{
    int error = 1;

    if (fileManagerIsCreated)
    {
        Vertex* ultimate = NULL;
        int lastSlashIndex = -1;
        bool isDirectory;
        ultimate = FindUltimateDirectoryInPath(path);

        if (ultimate)
        {
            if (recursive == 0)
            {
                if (ultimate->child == NULL)
                {
                    Vertex* left = NULL, * right = NULL;

                    if (ultimate->rightbrother && ultimate->leftbrother)
                    {
                        if (ultimate == currentDirectory)
                        {
                            currentDirectory = root;
                        }
                        diskSize += ultimate->size;
                        left = ultimate->leftbrother;
                        right = ultimate->rightbrother;

                        right->leftbrother = left;

                        free(left->rightbrother->name);
                        free(left->rightbrother);
                        left->rightbrother = right;
                    }
                    else if (ultimate->leftbrother)
                    {
                        if (ultimate == currentDirectory)
                        {
                            currentDirectory = root;
                        }
                        diskSize += ultimate->size;
                        left = ultimate->leftbrother;
                        free(left->rightbrother->name);
                        free(left->rightbrother);
                        left->rightbrother = NULL;
                    }
                    else if (ultimate->rightbrother)
                    {
                        if (ultimate == currentDirectory)
                        {
                            currentDirectory = root;
                        }
                        diskSize += ultimate->size;
                        right = ultimate->rightbrother;
                        free(right->leftbrother->name);
                        free(right->leftbrother);
                        right->leftbrother = NULL;
                        right->parent->child = right;
                    }
                    else if (strcmp(ultimate->name, "/") != 0)
                    {
                        if (ultimate == currentDirectory)
                        {
                            currentDirectory = root;
                        }
                        diskSize += ultimate->size;
                        Vertex* parent = ultimate->parent;
                        free(parent->child->name);
                        free(parent->child);
                        parent->child = NULL;
                    }
                    else
                    {
                        free(root->name);
                        root->name = NULL;
                        free(root);
                        root = NULL;
                    }
                }
                else
                    error = 0;
            }
            else if (recursive == 1) // recursive === 1
            {
                Vertex* child = ultimate->child, *left, *right;

                if (child)
                {
                    while (child != ultimate)
                    {
                        while (child->child)
                        {
                            child = child->child;
                        }
                        if (child->rightbrother)// Second child kills first child and becomes first in list
                        {
                            if (child == currentDirectory)
                            {
                                currentDirectory = root;
                            }
                            diskSize += child->size;
                            child = child->rightbrother;
                            /*child->leftbrother->parent = NULL;
                            child->leftbrother->rightbrother = NULL;*/
                            free(child->leftbrother->name);
                            /*child->leftbrother->name = NULL;*/
                            free(child->leftbrother);
                            child->leftbrother = NULL;
                            child->parent->child = child;
                        }
                        else // Parent kills its child
                        {
                            if (child == currentDirectory)
                            {
                                currentDirectory = root;
                            }
                            diskSize += child->size;
                            child = child->parent;
                            free(child->child->name);
                            /*child->child->name = NULL;
                            child->child->parent = NULL;*/
                            free(child->child);
                            child->child = NULL;
                        }
                    }
                }
                if (ultimate->rightbrother && ultimate->leftbrother)
                {
                    if (ultimate == currentDirectory)
                    {
                        currentDirectory = root;
                    }
                    diskSize += ultimate->size;
                    left = ultimate->leftbrother;
                    right = ultimate->rightbrother;

                    right->leftbrother = left;

                    free(left->rightbrother->name);
                    free(left->rightbrother);
                    left->rightbrother = right;
                }
                else if (ultimate->leftbrother)
                {
                    if (ultimate == currentDirectory)
                    {
                        currentDirectory = root;
                    }
                    diskSize += ultimate->size;
                    left = ultimate->leftbrother;
                    free(left->rightbrother->name);
                    free(left->rightbrother);
                    left->rightbrother = NULL;
                }
                else if (ultimate->rightbrother)// Second child kills first child and becomes first in list
                {
                    if (ultimate == currentDirectory)
                    {
                        currentDirectory = root;
                    }
                    diskSize += ultimate->size;
                    ultimate = ultimate->rightbrother;
                    free(ultimate->leftbrother->name);
                    free(ultimate->leftbrother);
                    ultimate->leftbrother = NULL;
                    ultimate->parent->child = ultimate;
                }
                else if(strcmp(ultimate->name, "/") != 0)// Parent kills its child
                {
                    if (ultimate == currentDirectory)
                    {
                        currentDirectory = root;
                    }
                    diskSize += ultimate->size;
                    ultimate = ultimate->parent;
                    free(ultimate->child->name);
                    ultimate->child->name = NULL;
                    ultimate->child->parent = NULL;
                    free(ultimate->child);
                    ultimate->child = NULL;
                }
                else
                {
                    free(root->name);
                    root->name = NULL;
                    free(root);
                    root = NULL;
                }
            }
            else
                error = 0;
        }
        else
            error = 0;
    }
    else
        error = 0;

    return error;
}

int MyDestroy()
{
    if (fileManagerIsCreated)
    {
        MyRemove("/", 1);
        currentDirectory = NULL;
        root = NULL;
        fileManagerIsCreated = false;
    }
    else
        return 0;

    return 1;
}

void setup_file_manager(file_manager_t* fm)
{
    fm->create = MyCreate;
    fm->free_space = MyFreeSpace;
    fm->create_dir = MyCreateDirectory;
    fm->create_file = MyCreateFile;
    fm->get_cur_dir = MyGetCurrentDirectory;
    fm->change_dir = MyChangeDirectory;
    fm->remove = MyRemove;
    fm->destroy = MyDestroy;
}
