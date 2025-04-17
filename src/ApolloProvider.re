open ApolloClient;

[@bs.module "@apollo/client"] [@react.component]
external make:
  (~client: generatedApolloClient, ~children: React.element) => React.element =
  "ApolloProvider";
