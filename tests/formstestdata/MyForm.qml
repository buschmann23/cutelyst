import QtQuick 2.0
import org.cutelyst.forms 1.0

Form {
    htmlId: "littleForm"
    htmlClass: "form"
    name: "littleForm"
    label: cTr("%n dwarf(s)", "", dwarfsCount)

    buttons: [
        Button {

        },
        Button {

        }
    ]

    Fieldset {
        htmlId: "fieldset1"
        htmlClass: test
        legend: Legend {
            text: "A greate legend"
        }

        Select {
            htmlId: "selectField"

            Option {
                label: "optionLabel"
            }
        }

        Select {
            Optgroup {
                label: "Group A"
                Option {
                    text: "Opt 1"
                    value: "1"
                }
                Option {
                    text: "Opt 2"
                    value: "2"
                }
            }
            Optgroup {
                label: "Group B"
                Option {
                    text: "Opt 3"
                    value: "3"
                }
                Option {
                    text: "Opt 4"
                    value: "4"
                }
            }
        }
    }

    Fieldset {
        htmlId: "fieldset2"
    }
}
