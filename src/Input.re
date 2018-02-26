type state = string;

let valueFromEvent = (event) : string => (
                                           event
                                           |> ReactEventRe.Form.target
                                           |> ReactDOMRe.domElementToObj
                                         )##value;

let component = ReasonReact.reducerComponent("Input");

let make = (~onSubmit, _) => {
  ...component,
  initialState: () => "",
  reducer: (newText, _text) => ReasonReact.Update(newText),
  render: ({state: text, reduce}) =>
    <input
      value=text
      _type="text"
      placeholder="Write Something todo"
      onChange=(reduce((evt) => valueFromEvent(evt)))
      onKeyDown=(
        (evt) =>
          if (ReactEventRe.Keyboard.key(evt) == "Enter") {
            onSubmit(text);
            (reduce(() => ""))()
          }
      )
    />
};
