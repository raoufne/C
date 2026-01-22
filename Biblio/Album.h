#ifndef ALBUM_H
#define ALBUM_H

#include "Livre.h"

enum TypeIllustration {
    PHOTOS,
    DESSINS,
    PHOTOS_ET_DESSINS
};

class Album : public Livre {

private:
    TypeIllustration typeIllustration;

public:
    Album();
    
    Album(string code, string auteur, string titre, string editeur,
          string isbn, Public publicCible, TypeIllustration typeIllustration);

    ~Album();

    void afficher() const override;
    string getType() const override;

    TypeIllustration getTypeIllustration() const;

    string typeIllustrationToString() const;
};

#endif