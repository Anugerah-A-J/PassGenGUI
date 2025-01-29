#include "passgen.h"
#include <vector>
#include <set>

PassGen::PassGen(QWidget *parent):
    QWidget{parent},
    checkBoxGroupBox{"Password contain:", this},
    checkBoxLayout{&checkBoxGroupBox},
    lowerCaseCheckBox{"a-z", this},
    upperCaseCheckBox{"A-Z", this},
    numberCheckBox{"0-9", this},
    symbolCheckBox{"!@#$%^&*()", this},
    passwordLengthLabel{"Password length:", this},
    passwordLengthSpinBox{this},
    generate{"Generate", this},
    passwordLabel{this},
    layout{this},
    lowerCase{"qwertyuiopasdfghjklzxcvbnm"},
    upperCase{"QWERTYUIOPASDFGHJKLZXCVBNM"},
    number{"1234567890"},
    symbol{"!@#$%^&*()"}
{
    checkBoxLayout.addWidget(&lowerCaseCheckBox, 0, 0);checkBoxLayout.addWidget(&upperCaseCheckBox, 0, 1);
    checkBoxLayout.addWidget(&numberCheckBox, 1, 0);checkBoxLayout.addWidget(&symbolCheckBox, 1, 1);

    layout.addWidget(&checkBoxGroupBox, 0, 0, 1, 2);
    layout.addWidget(&passwordLengthLabel, 1, 0);layout.addWidget(&passwordLengthSpinBox, 1, 1);
    layout.addWidget(&generate, 2, 0, 1, 2);
    layout.addWidget(&passwordLabel, 3, 0, 1, 2);

    lowerCaseCheckBox.setCheckState(Qt::Checked);
    upperCaseCheckBox.setCheckState(Qt::Checked);
    numberCheckBox.setCheckState(Qt::Checked);
    symbolCheckBox.setCheckState(Qt::Checked);
    numberCheckBox.setMinimumWidth(symbolCheckBox.width());
    passwordLengthSpinBox.setMinimum(9);
    passwordLengthSpinBox.setMaximum(99);
    passwordLabel.setAlignment(Qt::AlignCenter);

    connect(&generate, &QPushButton::clicked, this, &PassGen::generatePassword);
}

void PassGen::generatePassword()
{
    unsigned int passwordLength{static_cast<unsigned int>(passwordLengthSpinBox.value())};
    
    std::string password;
    password.reserve(passwordLength);

    std::vector<const std::string*> characterKindContainer;
    characterKindContainer.reserve(4);

    if (lowerCaseCheckBox.checkState() == Qt::Checked)
        characterKindContainer.push_back(&lowerCase);

    if (upperCaseCheckBox.checkState() == Qt::Checked)
        characterKindContainer.push_back(&upperCase);

    if (numberCheckBox.checkState() == Qt::Checked)
        characterKindContainer.push_back(&number);

    if (symbolCheckBox.checkState() == Qt::Checked)
        characterKindContainer.push_back(&symbol);

    if (characterKindContainer.empty())
    {
        passwordLabel.setText("");
        return;
    }

    std::uniform_int_distribution<> characterKindIndexDist{0, static_cast<int>(characterKindContainer.size() - 1)};
    std::vector<std::uniform_int_distribution<>> characterIndexDist;
    characterIndexDist.reserve(characterKindContainer.size());

    for (auto c : characterKindContainer)
        characterIndexDist.emplace_back(0, c->size() - 1);

    std::set<unsigned int> characterKindIndexContainer;
    unsigned int characterKindIndex;

    for (unsigned int i = 0; i < passwordLength; ++i)
    {
        characterKindIndex = characterKindIndexDist(rd);

        // characterKindContainer.size():
        // 2 -> tweak when characterKindIndexContainer.size() == 1 && i == passwordLength - 1
        // 3 -> tweak when characterKindIndexContainer.size() == 2 && i == passwordLength - 1
        // 3 -> tweak when characterKindIndexContainer.size() == 1 && i == passwordLength - 2
        // ....
        // tweak when characterKindIndexContainer.size() < characterKindContainer.size()
        // && i == passwordLength - (characterKindContainer.size() - characterKindIndexContainer.size())
        
        if (characterKindIndexContainer.size() < characterKindContainer.size()
            && i == passwordLength - (characterKindContainer.size() - characterKindIndexContainer.size()))
        {
            while(true)
            {
                if (characterKindIndexContainer.count(characterKindIndex) == 0)
                    break;

                characterKindIndex = characterKindIndexDist(rd);
            }
        }

        characterKindIndexContainer.insert(characterKindIndex);

        password.push_back(
            characterKindContainer.at(characterKindIndex)->at(
                characterIndexDist.at(characterKindIndex)(rd)
            )
        );
    }

    passwordLabel.setText(QString::fromStdString(password));
}
