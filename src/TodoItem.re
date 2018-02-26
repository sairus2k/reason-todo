type item = {
  id: int,
  title: string,
  completed: bool
};

let str = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("TodoItem");

let make = (~item, ~onToggle, children) => {
  ...component,
  render: (self) =>
    <label className="item">
      <input
        _type="checkbox"
        checked=(Js.Boolean.to_js_boolean(item.completed))
        onChange=((_evt) => onToggle())
      />
      (str(item.title))
    </label>
};
