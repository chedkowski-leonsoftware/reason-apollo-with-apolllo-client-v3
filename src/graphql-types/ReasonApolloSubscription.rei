open! ReasonApolloTypes;

module Make:
  (Config: ReasonApolloTypes.Config) =>
   {
    [@bs.module "@apollo/client"] external gql: ReasonApolloTypes.gql = "gql";

    let graphQLSubscriptionAST: queryString;

    type response = subscriptionResponse(Config.t);

    type renderPropObj = {
      result: response,
      data: option(Config.t),
      error: option(apolloError),
      loading: bool,
    };

    type renderPropObjJS = {
      loading: bool,
      data: Js.Nullable.t(Js.Json.t),
      error: Js.Nullable.t(apolloError),
    };

    let apolloDataToVariant: renderPropObjJS => response;

    let convertJsInputToReason: renderPropObjJS => renderPropObj;

    module JsSubscription: {
      [@bs.module "@apollo/client"] [@react.component]
      external make:
        (
          ~subscription: ReasonApolloTypes.queryString,
          ~variables: option(Js.Json.t),
          ~children: renderPropObjJS => ReasonReact.reactElement
        ) =>
        ReasonReact.reactElement =
        "Subscription";
    };

    [@react.component]
    let make:
      (~variables: Js.Json.t=?, ~children: renderPropObj => React.element) =>
      React.element;
  };
